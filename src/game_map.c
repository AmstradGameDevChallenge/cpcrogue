#include <cpctelera.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "constants.h"
#include "conio.h"
#include "fast_math.h"
#include "entity.h"
#include "rect.h"
#include "fov.h"
#include "game_map.h"

// Forward declarations of private functions
void _PlaceRoom (TRoom *r);
void _InitTiles (u8 width, u8 height);
u8 _InitGrid ();
void _Map2Tiles (TEntity *player, u8 num_rooms);
void _CreateTunnel (u8 start, u8 end, u8 other, u8 direction);
void _GetView (u8 *left, u8 *top, TEntity *player);


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
u8 MapIsBlocked (u8 x, u8 y)
{
  return game_map.tiles[y][x].t_flags & BLOCKED;
}

/*
 * \param[in] x,y Map coordinates to query.
 *
 * \returns true if tile blocks light.
 */
u8 MapBlocksLight (u8 x, u8 y)
{
  return game_map.tiles[y][x].t_flags & BLOCKS_LIGHT;
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
  u8 fg_pen, bg_pen;
  u8 ch;

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

    // reference to the current tile
    current_tile = &game_map.tiles[top + y][left + x];

    visible = isVisible (left + x, top + y);
    is_wall = current_tile->t_flags & BLOCKED;
    fg_pen = bg_pen = PEN_CLEAR;

  /*
   * TODO:
   *  - shorter version avoid if - else - if?
   */
    /*
     * Tile VISIBLE
     */
    if (visible) {
      fg_pen = PEN_NORMAL;    // Uses light color

      if (is_wall) {            // WALL (lighted)
        bg_pen = PEN_BRIGHT;
        ch = SPR_WALL;          // Sprite used to draw a WALL
      } // if is_wall
      else {                    // FLOOR (lighted)
        bg_pen = PEN_CLEAR;
        ch = SPR_FLOOR;         // Sprite used to draw a FLOOR
      } // else

      // Draw tile
      putchar_f (VMEM_MAP, x, y, ch, fg_pen, bg_pen);

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
      putchar_f (VMEM_MAP, x, y, ch, fg_pen, bg_pen);
    } // else if explored
    /*
     * Not visible/unexplored tiles are ignored.
     */
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
//---------------------------------------------------------------------------
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
void _InitTiles (u8 width, u8 height)
{
  game_map.width = width;
  game_map.height = height;

  // Initialize all tiles as block movement (walls) and block light
  cpct_memset (game_map.tiles, BLOCKED | BLOCKS_LIGHT,
    MAP_WIDTH * MAP_HEIGHT);

  // Initialize the visibility map
  ClearVisMap ();
}
//---------------------------------------------------------------------------
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
void _Map2Tiles (TEntity *player, u8 num_rooms)
{
  TRoom *rptr;
  u8 i;
  u8 new_x, new_y, prev_x, prev_y;

  new_x = new_y = prev_x = prev_y = 0;
  for (i=0,rptr = rooms; rptr != &rooms[num_rooms]; ++rptr, ++i) {
    // Fill room with floor
    _PlaceRoom (rptr);

    // Center coords of this room for later use
    RectGetCenter (&(rptr->rect), &new_x, &new_y);

    // Add player to first room
    if (i == 0) {
      player->x = new_x;
      player->y = new_y;
    }
    // All rooms after the first:
    // connect it to the previous room with a tunnel
    else {
      _CreateTunnel (prev_x, new_x, prev_y, true);
      _CreateTunnel (prev_y, new_y, new_x, false);
    }
    prev_x = new_x;
    prev_y = new_y;
    }

  // TODO: Add doors

}