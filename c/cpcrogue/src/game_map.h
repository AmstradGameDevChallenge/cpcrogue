#include "cpctelera.h"
#include "constants.h"
#include "room.h"

// Single tile information
typedef struct {
  u8 blocked;
} TTile;

// Tiles in the map
typedef struct {
  u8 width;
  u8 height;
  TTile tiles[MAP_HEIGHT][MAP_WIDTH];
} TMap;

// Grid cell to distribute rooms
typedef struct {
  u8 x,y;
  u8 room_id;
} TGridCell;

void MapCreate (u8 width, u8 height, TEntity *player);
void _CreateTunnel (u8 start, u8 end, u8 other, u8 direction);
u8 MapIsBlocked (u8 x, u8 y);
void MapDraw (u8 left, u8 right);
void GetView (TEntity* player, u8 *left, u8 *top);

// Grid cells
extern TGridCell grid[];

// Map tiles
extern TMap game_map;

// Rooms placed in map
extern TRoom rooms[];
