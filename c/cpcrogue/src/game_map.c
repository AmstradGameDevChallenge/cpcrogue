#include <stdio.h>
#include "conio.h"
#include "constants.h"
#include "fast_math.h"
#include "entity.h"
#include "room.h"
#include "game_map.h"

/****************************************************************************
 *             Create a game map
 ***************************************************************************/
void MapCreate (u8 width, u8 height, TEntity *player)
{
  Room r1;                // Room to place
  Room rooms[MAX_ROOMS]; // Rooms placed in map
  u8 x,y;                 // x,y for the new room room
  u8 w,h;                 // width, height for the new room
  u8 new_x, new_y;
  u8 prev_x, prev_y;
  u8 num_rooms;   // Count of how many rooms are in place
  u8 overlaps;

  // Initialize all tiles as blocked (walls everywhere)
  game_map.width = width;
  game_map.height = height;
  cpct_memset (game_map.tiles, TRUE, MAP_WIDTH * MAP_HEIGHT);

  num_rooms = 0;
  new_x = new_y = prev_x = prev_y = 0;

  do {
    // Random width and height
    w = rand_range (ROOM_MIN_SIZE, ROOM_MAX_SIZE);
    h = rand_range (ROOM_MIN_SIZE, ROOM_MAX_SIZE);

    // random position within boundaries of the map
    x = rand_range (0, MAP_WIDTH - w -1);
    y = rand_range (0, MAP_HEIGHT - h -1);

    _RoomCreate (&r1, x,y, w, h);

    // CHECK IF THIS ROOM DOES NOT OVERLAP OTHER ROOM
    overlaps = FALSE;
    for (u8 r=0; r!=num_rooms; ++r) {
      if (_RoomOverlaps (&r1, &rooms[r])) {
        overlaps = TRUE;
        break;
      }
    }
    if (!overlaps) {

      _PlaceRoom (&r1);

      // Center coords of this room for later use
      _GetCenter (&r1, &new_x, &new_y);

      if (num_rooms == 0) {
        // First room, player starts at it
        player->x = new_x;
        player->y = new_y;
      }
      else {
        // All rooms after the first:
        // connect it to the previous room with a tunnel
        _CreateTunnel (prev_x, new_x, prev_y, TRUE);
        _CreateTunnel (prev_y, new_y, new_x, FALSE);
      }
      prev_x = new_x;
      prev_y = new_y;
      cpct_memcpy (&rooms [num_rooms], &r1, sizeof (Room));
    }
    ++num_rooms;
      /*    prev_x = new_x;
      prev_y = new_y;
      cpct_memcpy (&rooms [num_rooms], &r1, sizeof (Room));*/

  } while (num_rooms != MAX_ROOMS);
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
void _PlaceRoom (Room *r)
{
  u8 x,y;
  for (y = r->y1+1; y < r->y2; ++y) {
    for (x = r->x1+1; x < r->x2; ++x) {ç
      game_map.tiles[y][x].blocked = FALSE;
    }
  }
}
//---------------------------------------------------------------------------
u8 MapIsBlocked (u8 x, u8 y)
{
  return game_map.tiles[y][x].blocked;
}
//---------------------------------------------------------------------------
void MapDraw ()
{
  extern TMap game_map;
  u8 i,j;
  u8 is_wall;

  // Draw Map
  for (i=0; i < game_map.height; ++i) {
    for (j=0; j < game_map.width; ++j) {
      locate (PLAY_X+j,PLAY_Y+i);
      is_wall = game_map.tiles[i][j].blocked;
      pen (PEN_TILE);
      if (is_wall) {
        putchar(SPR_WALL);
      }
      else {
        putchar (SPR_FLOOR);
      }
    }
  }
}

TMap game_map;