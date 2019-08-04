#include <stdio.h>
#include "game_map.h"
#include "conio.h"


/****************************************************************************
 *              GAME MAP
 ***************************************************************************/
void MapCreate (u8 width, u8 height)
{
  extern TMap game_map;
  u8 i, j;
  game_map.width = width;
  game_map.height = height;
  for (i=0; i < height; ++i)
    for (j=0; j < width; ++j)
      game_map.tiles[i][j].blocked = FALSE;

  // Tiles are referenced first vertical (Y), then horizontal (X)
  game_map.tiles[12][3].blocked = TRUE;
  game_map.tiles[3][16].blocked = TRUE;
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