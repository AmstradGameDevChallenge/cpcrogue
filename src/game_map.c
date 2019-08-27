//-----------------------------LICENSE NOTICE--------------------------------
//  This file is part of CPCRogue: An Amstrad CPC rogue like game
//  Copyright (C) 2019 Andrés Mata Bretón (@FlautinesMata)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//---------------------------------------------------------------------------
#include <cpctelera.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "constants.h"
#include "conio.h"
#include "fast_math.h"
#include "components/fighter.h"
#include "entity.h"
#include "rect.h"
#include "fov.h"
#include "game_map.h"

// Forward declarations of private functions
void _PlaceRoom (TRoom *r);
void _InitTiles (u8 width, u8 height);
u8   _InitGrid ();
void _Map2Tiles (TEntity *player, u8 num_rooms);
void _CreateTunnel (u8 start, u8 end, u8 other, u8 direction);
void _GetView (u8 *left, u8 *top, TEntity *player);
void _MapPlaceEntities (TRoom *rptr);

//===========================================================================
//===========================================================================
/***
 *       ___  _  _ ___  _    _ ____
 *       |__] |  | |__] |    | |
 *       |    |__| |__] |___ | |___
 *    ____ _  _ _  _ ____ ___ _ ____ _  _ ____
 *    |___ |  | |\ | |     |  | |  | |\ | [__
 *    |    |__| | \| |___  |  | |__| | \| ___]
 *
 */
//===========================================================================
//===========================================================================

// Instantiate the lobal variables used in this module
TGridCell grid[GRID_WIDTH * GRID_HEIGHT];
TRoom rooms[MAX_ROOMS];

/*!
 * The global variable **game_map** holds information about the tiles in the
 * current generated map. It's a global variable and can be accessed from
 * any file to query information about a specific tile or dimensions of the
 * map.
 */
TMap game_map;

/*!
 * Creates a new dungeon of given dimensions and places the player on it.
 * Dungeons bigger than the displayable area are allowed.
 * The dungeon is randomly created by following these steps:
 *  - Fill the whole map with walls
 *  - Create a bunch of rooms
 *  - Distribute the rooms on a grid based pattern
 *  - Connect the rooms
 *
 * The player is placed at the first room.
 *
 * \param[in] width Width of the map
 * \param[in] height Height of the map
 * \param[out] player Player to place in the map
 */
void MapCreate (u8 width, u8 height, TEntity *player)
{
  u8 num_rooms;
  // Initialize all the tiles (width x height tiles)
  _InitTiles (width, height);

  // Create rooms and place them in the grid
  num_rooms = _InitGrid ();

  // Transfer room information to the tiles
  _Map2Tiles (player, num_rooms);
}

//---------------------------------------------------------------------------
/*! \brief
 *

u8 MapIsBlocked (u8 x, u8 y)
{
  return game_map.tiles[y][x].t_flags & BLOCKED;
}
*/

/*
 * \param[in] x,y Map coordinates to query.
 *
 * \returns true if tile blocks light.
 */
u8 MapBlocksLight (u8 x, u8 y)
{
  return game_map.tiles[y][x].t_flags & BLOCKS_LIGHT;
}

void MapDrawTile (TTile *current_tile,
  u8 view_x, u8 view_y, u8 tile_x, u8 tile_y,
  u8 visible, u8 is_wall)
{
  u8 fg_pen, bg_pen;
  u8 ch;
  fg_pen = bg_pen = PEN_CLEAR;

  if (visible) {
  /*
   * Tile VISIBLE
   */
    fg_pen = PEN_NORMAL;    // Uses light color

    if (is_wall) {            // WALL (lighted)
      bg_pen = PEN_BRIGHT;
      ch = SPR_WALL;          // Sprite used to draw a WALL
    } // if is_wall
    else {
                              // FLOOR (lighted)
      bg_pen = PEN_CLEAR;
      ch = SPR_FLOOR;         // Sprite used to draw a FLOOR
    } // else (!is_wall)

    // Draw tile
    if (MapHasDeadEntity (tile_x, tile_y))
      putchar_f (VMEM_MAP, view_x, view_y, '%', fg_pen, bg_pen);
    else if (!MapHasEntity (tile_x, tile_y))
      putchar_f (VMEM_MAP, view_x, view_y, ch, fg_pen, bg_pen);


    // Mark this tile as explored
    current_tile->t_flags |= EXPLORED;

  } // if visible
  /*
   * Tile HIDDEN
   */
  else if (current_tile->t_flags & EXPLORED) {
    fg_pen = PEN_EXPLORED;    // Explored tiles are drawn darker

    if (is_wall) {              // WALL (dark)
      bg_pen = PEN_CLEAR;
      ch = SPR_WALL;            // Sprite to draw a WALL
    }
    else {
      bg_pen = PEN_CLEAR;
      ch = SPR_FLOOR;           // FLOOR (dark)
    }
    putchar_f (VMEM_MAP, view_x, view_y, ch, fg_pen, bg_pen);
  } // else if explored
  /*
   * Not visible/unexplored tiles are ignored.
 */
}
/*!
 * Draws a portion of the map into the viewport. The start coordinates of
 * the subregion in the map to draw are given by *left* and *top*
 * parameters.
 *
 * Not explored areas are ignored, and thus show as black areas as expected.
 * Explored areas visible by the player are drawn as lighted tiles whereas
 * not visible are drawn darker.
 *
 * Drawing the full viewport is too slow to the Amstrad CPC, so only a small
 * area around the player is drawn. Right now, this area is hardcoded as **FOV_RADIUS** +1. **TODO:** pass the area to be drawn as parameters
 * *width* and *height*.
 *
 * \param left  left tile coordinate from the game map to draw
 * \param top   top map coordinates from the game map to draw
 * \param player Player entity
 */
//---------------------------------------------------------------------------
void MapDraw (u8 left, u8 top, u8 width, u8 height, TEntity *player)
{
  //void *pvmem;
  u8 is_wall, visible;
  TTile *current_tile;
  u8 tile_x, tile_y;  // Coords of the map tile to draw


  /*
   * TODO:
   *  - use width and height to determine drawing area
   *  - take out limit calculation from the 'for' loop
   *  - Accept vmem start address so we can draw in a secondary buffer
   */
  for (i8 y = player->y-top-FOV_RADIUS-1; y <= player->y-top+FOV_RADIUS+1; ++y) {
  for (i8 x = player->x-left-FOV_RADIUS-1; x <= player->x-left+FOV_RADIUS+1; ++x) {

    // keep the calculated drawing area within the viewport limits
    x = x < 0 ? 0: x;
    y = y < 0 ? 0: y;
    if (x> VIEW_WIDTH-1) break;
    if (y> VIEW_HEIGHT-1) break;

    tile_x = left + x;
    tile_y = top + y;
    // reference to the current tile
    current_tile = &game_map.tiles[tile_y][tile_x];

    visible = isVisible (tile_x, tile_y);
    is_wall = current_tile->t_flags & BLOCKED;

    MapDrawTile (current_tile, x, y, tile_x, tile_y, visible, is_wall);
    } // for x
  } // for y
}

//---------------------------------------------------------------------------
void GetView (TEntity* player, u8 *left, u8 *top, u8 width, u8 height)
{
  // Center view around player
  register i8 l,t;

  l = player->x - (width / 2);
  t = player->y - (height / 2);

  l = l < 0 ? 0 : l;
  t = t < 0 ? 0 : t;

  l = l + width > MAP_WIDTH ? MAP_WIDTH - width : l;
  t = t + height > MAP_HEIGHT ? MAP_HEIGHT - height : t;

  *left = l;
  *top = t;
}
//===========================================================================
//===========================================================================
/***
 *       ___  ____ _ _  _ ____ ___ ____
 *       |__] |__/ | |  | |__|  |  |___
 *       |    |  \ |  \/  |  |  |  |___
 *    ____ _  _ _  _ ____ ___ _ ____ _  _ ____
 *    |___ |  | |\ | |     |  | |  | |\ | [__
 *    |    |__| | \| |___  |  | |__| | \| ___]
 *
 */
//===========================================================================
//===========================================================================

/*! \brief
 * Initializes the map to a given width and height.
 *
 * All the tiles in the map  are set to block movement and light. Also
 * initializes the visibility map to all cells not visible.
 *
 * \param width   Width of the map to initialize
 * \param height  Height of the map to initialize
 */
void _InitTiles (u8 width, u8 height)
{
  game_map.width = width;
  game_map.height = height;

  // Initialize all tiles as block movement (walls) and block light
  cpct_memset (game_map.tiles, BLOCKED | BLOCKS_LIGHT,
    sizeof (game_map.tiles));

  // Initialize the visibility map
  ClearVisMap ();
}

//---------------------------------------------------------------------------
/*! \brief
 * Initializes the grid system by which the rooms will be placed.
 *
 * Each room is placed in a single grid cell, thus we ensure no rooms
 * overlap. This fn. does the following:
 *
 *  - Zero all rooms data
 *  - Create a rnd # of rooms of rnd size
 *  - Set the top,left coordinate of each grid cell
 *  - Place a room in a rnd grid cell
 *
 * After this function is called each tile has a room id assigned to it.
 * But the room tiles are not yet "carved"on the map. That's the role of
 * \ref _Map2Tiles which is called next.
 */
u8 _InitGrid ()
{
  TRoom *rptr;            // Room to place
  u8 x,y;                 // x,y for the new room room
  u8 w,h;                 // width, height for the new room
  u8 num_rooms;           // How many rooms
  u8 i;
  u8 spot;                // Empty spot in the grid

  // Zero all rooms
  cpct_memset (rooms, 0, MAX_ROOMS * sizeof (TRoom));

  // How many rooms
  num_rooms = rand_range (MIN_ROOMS, MAX_ROOMS);

  // Build that many rooms
  for (rptr = rooms; rptr != &rooms[num_rooms]; rptr++) {
    w = rand_range (MIN_ROOM_SIZE, MAX_ROOM_SIZE);
    h = rand_range (MIN_ROOM_SIZE, MAX_ROOM_SIZE);
    RectCreate (&(rptr->rect), 0,0, w, h);
  }

  // Setup the grid coordinates of each spot (cell) and
  // all cells are empty
  for (i=0; i != GRID_WIDTH*GRID_HEIGHT; ++i) {
    x = (i%GRID_WIDTH) * SPOTS_IN_GRID;
    y = (i/GRID_WIDTH) * SPOTS_IN_GRID;
    grid[i].x = x;
    grid[i].y = y;
    grid[i].room_id = ROOM_NONE;
  }

  // Add rooms to grid
  for (i=0, rptr=rooms; rptr != &rooms[num_rooms]; ++i, ++rptr) {
    // Find an empty spot on the grid
    do {
      spot = rand_range (0, GRID_WIDTH * GRID_HEIGHT);
    } while (grid[spot].room_id != ROOM_NONE);

    // Create room
    x = grid[spot].x;
    y = grid[spot].y;
    RectCreate (&(rptr->rect), x,y, rptr->rect.width,rptr->rect.height);
    grid[spot].room_id = i;
  }
  return num_rooms;
}

//---------------------------------------------------------------------------
/*! \brief
 * "Carve" rooms, places entities in and connects them.
 */
void _Map2Tiles (TEntity *player, u8 num_rooms)
{
  TRoom *rptr;
  u8 i;
  u8 new_x, new_y, prev_x, prev_y;
  new_x = new_y = prev_x = prev_y = 0;

  // For each room...
  for (i=0,rptr = rooms; rptr != &rooms[num_rooms]; ++rptr, ++i) {

    // Fill room with floor tiles
    _PlaceRoom (rptr);

    // Center coords of this room for later use
    RectGetCenter (&(rptr->rect), &new_x, &new_y);

    // Add player to first room
    if (i == 0) {
      player->x = new_x;
      player->y = new_y;

      // Flag this tile is now occupied
      game_map.tiles[new_y][new_x].t_flags |= HAS_ENTITY;
    } // if

    // All rooms after the first:
    // connect it to the previous room with a tunnel
    else {
      _CreateTunnel (prev_x, new_x, prev_y, true);
      _CreateTunnel (prev_y, new_y, new_x, false);

      // Add enemies to this room
      _MapPlaceEntities (rptr);
    } // else

    // Save this room coords. to create a tunnel to the next room.
    prev_x = new_x;
    prev_y = new_y;
  } // for

  // TODO: Add doors
}

//--------------------------------------------------------------------------
/*! \brief
 *  Fill a room with corresponding tiles and set not blocking flags.
 *
 *  \param r Pointer to room to place
 *
 */
void _PlaceRoom (TRoom *r)
{
  u8 x,y;
  for (y = r->rect.top+1; y < r->rect.bottom-1; ++y) {
    for (x = r->rect.left+1; x < r->rect.right-1; ++x) {
      game_map.tiles[y][x].t_flags &= ~BLOCKED;
      game_map.tiles[y][x].t_flags &= ~BLOCKS_LIGHT;
    }
  }
}

//---------------------------------------------------------------------------
void _CreateTunnel (u8 start, u8 end, u8 other, u8 direction)
{
  u8 coord, x, y;
  u8 start_loop, end_loop;
  start_loop = min (start, end);
  end_loop = max (start, end);

  for (coord = start_loop; coord <= end_loop; ++coord) {
    if (direction) {
      // true Horizontal tunnel
      x = coord; y = other;
    }
    else {
      // FALSE Vertical tunnel
      x = other; y = coord;
    }
    game_map.tiles[y][x].t_flags &= ~BLOCKED;
    game_map.tiles[y][x].t_flags &= ~BLOCKS_LIGHT;
  }
}

//---------------------------------------------------------------------------
/*!
 * Places 0 to MAX_MOBS_IN_ROOM enemies in a room
 *
 * \param rptr Pointer to room to place the enemies
 *
 */
void _MapPlaceEntities (TRoom *rptr)
{
  u8 x, y;
  TFighter *mob_fighter;

  // Get a random # of mobs to place
  u8 num_mobs = rand_range (0, MAX_MOBS_IN_ROOM);

  for (u8 i=0; i<num_mobs; ++i) {

    // If there are no more memory for another mob, just exit
    if (num_entities == MAX_ENTITIES) return;

    assert (num_entities < MAX_ENTITIES);
    // Choose a random position in room
    x = rand_range (rptr->rect.left+1, rptr->rect.right-1);
    y = rand_range (rptr->rect.top+1, rptr->rect.bottom-1);

    // 80% create a goblin
    // 20% create an orc
    if (cpct_rand() < 128) {
      mob_fighter = FighterCreate (7, 12, 12, 10);
      EntityCreate (x, y, SPR_GOBLIN, PEN_NORMAL, "Goblin", true,
                    mob_fighter);
    } // if
    else {
      mob_fighter = FighterCreate (17, 14, 10, 9);
      EntityCreate (x, y, SPR_ORC, PEN_NORMAL, "Orc", true,
                    mob_fighter);
         ;
    } // else

  }

}
