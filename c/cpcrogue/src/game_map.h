#include "cpctelera.h"
#include "constants.h"
#include "entity.h"
#include "rect.h"

// Single tile information
typedef struct {
  u8 t_flags;
} TTile;

// Tiles in the map
typedef struct {
  u8 width;
  u8 height;
  TTile tiles[MAP_HEIGHT][MAP_WIDTH];
} TMap;

// Room info
typedef struct {
  TRect rect;   // x,y, width, height including walls
  u8 grid_id;   // Grid id where the room is placed
} TRoom;

// Grid cell to distribute rooms
typedef struct {
  u8 x,y;
  u8 room_id;
} TGridCell;

// Grid cells
extern TGridCell grid[];

// Map tiles
extern TMap game_map;

// Rooms placed in map
extern TRoom rooms[];

void MapCreate (u8 width, u8 height, TEntity *player);

u8 MapIsBlocked (u8 x, u8 y);
u8 MapBlocksLight (u8 x, u8 y);

// Sets area around origin_x/_y to not visible
void MapSetNotVisible (u8 origin_x, u8 origin_y, u8 range);

void MapDraw (u8 left, u8 right, u8 width, u8 height, TEntity *player);
void GetView (TEntity* player, u8 *left, u8 *top, u8 width, u8 height);

inline void MapSetVisible (u8 x, u8 y) {
  game_map.tiles[y][x].t_flags |= VISIBLE;
}
