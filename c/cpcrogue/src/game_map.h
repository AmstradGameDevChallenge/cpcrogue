#include "cpctelera.h"
#include "constants.h"

//---------------------------------------------------------------------------
typedef struct TTile {
  u8 blocked;
} TTile;
//---------------------------------------------------------------------------
typedef struct TMap {
  u8 width;
  u8 height;
  TTile tiles[MAP_HEIGHT][MAP_WIDTH];
} TMap;

void MapCreate (u8 width, u8 height);
u8 MapIsBlocked (u8 x, u8 y);
void MapDraw ();

extern TMap game_map;