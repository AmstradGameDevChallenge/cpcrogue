#include <stdio.h>
#include "conio.h"
#include "constants.h"
#include "fast_math.h"
#include "entity.h"
#include "rect.h"
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
  return game_map.tiles[y][x].t_flags & BLOCKED;
}
u8 MapBlocksLight (u8 x, u8 y)
{
  return game_map.tiles[y][x].t_flags & BLOCKS_LIGHT;
}
void MapSetNotVisible (u8 origin_x, u8 origin_y, u8 range)
{
  TRect area;

  // Create a Rect around the origin
  RectCreate (&area, origin_x - range, origin_y - range,
    range*2+1, range*2+1);
  for (u8 y=area.top; y < area.bottom; ++y) {
    for (u8 x=area.left; x < area.right; ++x) {
      game_map.tiles[y][x].t_flags &= ~VISIBLE;
    }
  }
}
//---------------------------------------------------------------------------
void MapDraw (u8 left, u8 top, u8 width, u8 height, TEntity *player)
{
  u8 is_wall, visible;
  TTile *current_tile;
  u8 fg_color, bg_color;
  u8 ch;


  // Draw map
  for (i8 y = player->y-top-FOV_RADIUS-1; y <= player->y-top+FOV_RADIUS+1; ++y) {
    for (i8 x = player->x-left-FOV_RADIUS-1; x <= player->x-left+FOV_RADIUS+1; ++x) {

//  for (u8 y=0; y != VIEW_HEIGHT; ++y) {
//    for (u8 x=0; x!= VIEW_WIDTH; ++x) {
      x = x < 0 ? 0: x;
      y = y < 0 ? 0: y;
      if (x> VIEW_WIDTH-1) break;
      if (y> VIEW_HEIGHT-1) break;
      current_tile = &game_map.tiles[top + y][left + x];
      visible = current_tile->t_flags & VISIBLE;
      is_wall = current_tile->t_flags & BLOCKED;
      fg_color = bg_color = PEN_CLEAR;

      if (visible) {
        fg_color = PEN_NORMAL;
        if (is_wall) {    // Lighted wall
          bg_color = PEN_BRIGHT;
          ch = SPR_WALL;
        }
        else {            // Lighted floor
          bg_color = PEN_CLEAR;
          ch = SPR_FLOOR;
        }
        locate (VIEW_X + x, VIEW_Y + y);
        pen (fg_color);
        paper (bg_color);
        putchar (ch);
        current_tile->t_flags |= EXPLORED;
      }
      else if (current_tile->t_flags & EXPLORED) {
        fg_color = PEN_EXPLORED;
        if (is_wall) {
          bg_color = PEN_CLEAR;
          ch = SPR_WALL;
        }
        else {
          bg_color = PEN_CLEAR;
          ch = SPR_FLOOR;
        }
        locate (VIEW_X + x, VIEW_Y + y);
        pen (fg_color);
        paper (bg_color);
        putchar (ch);
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
      // TRUE Horizontal tunnel
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
  cpct_memset (game_map.tiles, BLOCKED | BLOCKS_LIGHT & ~VISIBLE,
    MAP_WIDTH * MAP_HEIGHT);
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
      _CreateTunnel (prev_x, new_x, prev_y, TRUE);
      _CreateTunnel (prev_y, new_y, new_x, FALSE);
    }
    prev_x = new_x;
    prev_y = new_y;
    }

  // TODO: Add doors

}