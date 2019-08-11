#include <stdio.h>
#include "conio.h"
#include "constants.h"
#include "fast_math.h"
#include "entity.h"
#include "room.h"
#include "game_map.h"


void _PlaceRoom (TRoom *r);
void _InitTiles (u8 width, u8 height);
u8 _InitGrid ();
void _Map2Tiles (TEntity *player, u8 num_rooms);
void _CreateTunnel (u8 start, u8 end, u8 other, u8 direction);
void _GetView (u8 *left, u8 *top, TEntity *player);


/****************************************************************************
 *             Create a game map
 ***************************************************************************/
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
  return game_map.tiles[y][x].blocked;
}
//---------------------------------------------------------------------------
void MapDraw (u8 left, u8 top)
{
  u8 is_wall;
  TTile *current_tile;

  // Draw map
  for (u8 y = 0; y != VIEW_HEIGHT; ++y) {
    for (u8 x = 0; x != VIEW_WIDTH; ++x)
    {
      current_tile = &game_map.tiles[top + y][left + x];
      is_wall = current_tile->blocked;

      // Draw only if there's no wall
      locate (VIEW_X + x, VIEW_Y + y);
      if (is_wall) {
        pen (PEN_NORMAL);
        paper (PEN_BRIGHT);
        putchar (SPR_WALL);
      }
      else {
        paper (PEN_CLEAR);
        pen (PEN_NORMAL);
        putchar (SPR_FLOOR);
      }
    }
  }
  paper (PEN_CLEAR);
}

// Room id in each grid cell
TGridCell grid[GRID_WIDTH * GRID_HEIGHT];

// Rooms placed in map
TRoom rooms[MAX_ROOMS];

// Map tiles
TMap game_map;
//---------------------------------------------------------------------------
void GetView (TEntity* player, u8 *left, u8 *top)
{
  // Center view around player
  register i8 l,t;

  l = player->x - (VIEW_WIDTH / 2);
  t = player->y - (VIEW_HEIGHT / 2);

  l = l < 0 ? 0 : l;
  t = t < 0 ? 0 : t;

  l = l + VIEW_WIDTH > MAP_WIDTH ? MAP_WIDTH - VIEW_WIDTH : l;
  t = t + VIEW_HEIGHT > MAP_HEIGHT ? MAP_HEIGHT - VIEW_HEIGHT : t;

  *left = l;
  *top = t;
}
//---------------------------------------------------------------------------
void _PlaceRoom (TRoom *r)
{
  u8 x,y;
  for (y = r->top+1; y < r->bottom-1; ++y) {
    for (x = r->left+1; x < r->right-1; ++x) {
      game_map.tiles[y][x].blocked = FALSE;
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
      // TRUE Horizontal tunnel
      x = coord; y = other;
    }
    else {
      // FALSE Vertical tunnel
      x = other; y = coord;
    }
    game_map.tiles[y][x].blocked = FALSE;
  }
}
//---------------------------------------------------------------------------
void _InitTiles (u8 width, u8 height)
{
  // Initialize all tiles as blocked (walls everywhere)
  game_map.width = width;
  game_map.height = height;
  cpct_memset (game_map.tiles, TRUE, MAP_WIDTH * MAP_HEIGHT);
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
    RoomCreate (rptr, 0,0, w, h);
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
    RoomCreate (rptr, x,y, rptr->width,rptr->height);
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
    GetCenter (rptr, &new_x, &new_y);

    // Add player to first room
    if (i == 0) {
      player->x = new_x;
      player->y = new_y;
    }
    // All rooms after the first:
    // connect it to the previous room with a tunnel
    else {
      _CreateTunnel (prev_x, new_x, prev_y, TRUE);
      _CreateTunnel (prev_y, new_y, new_x, FALSE);
    }
    prev_x = new_x;
    prev_y = new_y;
    }

  // TODO: Add doors

}