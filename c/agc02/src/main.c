//-------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2018 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
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
//-----------------------------------------------------------------------------

/**********************************
 *  CPC ROGUE
 *  Jul 2019 by Andres Mata
 **********************************/
#include <cpctelera.h>
#include <stdio.h>
#include <string.h>

/****************************************************************************
 * Special ASCII codes
 ***************************************************************************/
#define US  0x1f        // LOCATE
#define FS  0x1c        // INK
#define GS  0x1d        // BORDER
#define SO  0x0e        // PAPER
#define SI  0x0f        // PEN
#define FF  0x0c        // CLS

// Boolean 'aliases'
#define TRUE 1
#define FALSE 0

// Max allowed entities in game
#define MAX_ENTITIES 5

// Map dimensions
#define MAP_WIDTH       20
#define MAP_HEIGHT      14

// Where the visible map starts, these offsets are added to
// everything we draw so they appear in the correct playable coordinates
#define PLAY_X            4
#define PLAY_Y            4

// Game Sprites
#define   SPR_WALL    "#"
#define   SPR_FLOOR   "."
#define   SPR_PLAYER  "@"
#define   SPR_GOBLIN  "g"

// Sprite Colors
#define   INK_DARK_TILE   1
#define   INK_LIGHT_TILE  13
#define   INK_ENTITY      20
#define   PEN_ENTITY      1
#define   PEN_TILE        2
#define   PEN_EXLORED     3

/****************************************************************************
 * Enumerations
 ***************************************************************************/
enum TActions {
  NONE, PLAYER_MOVED, ATTACK
};

/****************************************************************************
 * Data structures
 ***************************************************************************/
struct TEntity {
  u8 x, y;      // Current position
  u8 px, py;    // Previous position
  u8 spr[2];    // ASCII char to draw this entity
  u8 color;     // Color to draw this entity
  u8 name[15];  // Name to display in messages

  u16 max_hp;   // Max health
  u16 hp;       // Current health
  u8 str;       // Current strength
  u8 destr;     // Current dexterity
  u8 refl;      // Current reflexes
  u16 atk;      // Current attack
  u16 defense;  // Current defense
};
//---------------------------------------------------------------------------
struct TTile {
  u8 blocked;
};
//---------------------------------------------------------------------------
struct TRect {
  u8 x1;
  u8 y1;
  u8 x2;
  u8 y2;
};
//---------------------------------------------------------------------------
struct TMap {
  u8 width;
  u8 height;
  struct TTile tiles[MAP_HEIGHT][MAP_WIDTH];
};
/****************************************************************************
 * Video fn: LOCATE, INK, PAPER, BORDER, PEN, CLS
 ***************************************************************************/
void locate (u8 x, u8 y)
{
   putchar(US);
   putchar (x); putchar (y);
}
void ink (u8 tinta, u8 color1, u8 color2)
{
   putchar (FS);
   putchar (tinta); putchar (color1); putchar (color2);
}
void border (u8 color1, u8 color2)
{
   putchar (GS);
   putchar (color1); putchar (color2);
}
void paper (u8 color1)
{
   putchar (SO);
   putchar (color1);
}
void pen (u8 tinta)
{
   putchar (SI);
   putchar (tinta);
}
void cls () { putchar (FF); }
/****************************************************************************
 *                      PrintAt
 ***************************************************************************/
void PrintAt (u8 x, u8 y, char text[], u8 color)
{
  locate (x, y);
  if (color != 0xff) pen (color);
  printf (text);
}
/****************************************************************************
 * Map fns
 ***************************************************************************/
void MapCreate (struct TMap *map, u8 width, u8 height)
{
  int i, j;
  map->width = width;
  map->height = height;
  for (i=0; i < map->height; ++i)
    for (j=0; j < map->width; ++j)
      map->tiles[i][j].blocked = FALSE;

  // Tiles are referenced first vertical (Y), then horizontal (X)
  map->tiles[12][3].blocked = TRUE;
  map->tiles[3][1].blocked = TRUE;
}
//---------------------------------------------------------------------------
u8 MapCanMove (struct TMap *map, u8 x, u8 y)
{
  return !(map->tiles[y][x].blocked);
}
//---------------------------------------------------------------------------
void DrawMap (struct TMap *map)
{
  int i,j;
  u8 is_wall;

  // Draw Map
  for (i=0; i < map->height; ++i) {
    for (j=0; j < map->width; ++j) {
      is_wall = map->tiles[i][j].blocked;

      if (is_wall) {
        PrintAt (PLAY_X+j,PLAY_Y+i, "#", PEN_TILE);
      }
      else {
        PrintAt (PLAY_X+j,PLAY_Y+i, ".", PEN_TILE);
      }
    }
  }
}
/*
  This functions is not used yet, it's buggy!!

void draw_entities (struct TEntity* entities[])
{
  struct TEntity* e;

  u8 i = 0;
  while ( (e = entities[i++]) != NULL ) {
    PrintAt (PLAY_X+e->x, PLAY_Y+e->y, e->spr, e->color);
  }
}
*/

/****************************************************************************
 *                      Character Initialization
 ***************************************************************************/
void CharacterInit (struct TEntity *c,
   u8 x, u8 y, u8 spr[], u8 color, u8 name[],
   u16 hp, u8 str, u8 destr, u8 refl)
{
  c->x = x;         // current posX
  c->y = y;         // current posY
  c->px = c->x;     // Previous posX to current posX
  c->py = c->y;     // Previous posY to current posY
  strcpy (c->spr, spr);
  c->color = color;
  strcpy (c->name, name);

  c->max_hp = hp;
  c->hp = hp;
  c->str = str;
  c->destr = destr;
  c->refl = refl;

  c->atk = 1.5 * c->str + c->destr;
  c->defense = 1.5 * c->destr + c->refl;
}
//---------------------------------------------------------------------------
u8 CharacterMove (struct TMap *gm, struct TEntity *c, i8 dx, i8 dy)
{
  if (MapCanMove (gm, c->x+dx, c->y+dy)) {
    c->px = c->x;   // Save old positions
    c->py = c->y;
    c->x = c->x+dx;     // Update to new position
    c->y = c->y+dy;
    return TRUE;    // Flag we could move to the new position
  }
  return FALSE;
}
/****************************************************************************
 *                      Initialize Entities
 ***************************************************************************/
void InitEntities (struct TEntity* entities[])
{
  i8 i=MAX_ENTITIES-1;
  do {
    entities[i--] = NULL;
  } while (i != 0);
  entities[0] = NULL;
}

/****************************************************************************
 *                      Initialize Colors
 ***************************************************************************/
void InitColors()
{
  ink (0, 0,0);
  border (0,0); paper (0);

  ink (PEN_ENTITY, INK_ENTITY, INK_ENTITY);
  ink (PEN_TILE, INK_LIGHT_TILE, INK_LIGHT_TILE);
  ink (PEN_EXLORED, INK_DARK_TILE, INK_DARK_TILE);
}

/****************************************************************************
 *                      Display Character Stats
 ***************************************************************************/
void PrintCharacterStats (struct TEntity *c, u8 y,
   u8 color1, u8 color2)
{
  u8 num[5];
  PrintAt (3,y, "Movement: i:UP, k:DN, j:LT, k:RT", color2);
  PrintAt (1, y+1, "STR: ",color1);
  PrintAt (10,y+1, "DES: ",color1);
  PrintAt (20,y+1, "REF: ",color1);
  sprintf (num, "%d ", c->str);
  PrintAt (5,y+1, num, color2);
  sprintf (num, "%d ", c->destr);
  PrintAt (15,y+1, num, color2);
  sprintf (num, "%d ", c->refl);
  PrintAt (25,y+1, num, color2);

  PrintAt (1, y+2, "ATK: ", color1);
  PrintAt (10,y+2, "DEF: ", color1);
  PrintAt (20,y+2, " HP: ", color1);
  PrintAt (28,y+2, "/", color1);

  sprintf (num, "%d ", c->atk);
  PrintAt (5,y+2, num, color2);
  sprintf (num, "%d ",c->defense);
  PrintAt (15,y+2, num, color2);
  sprintf (num, "%d", c->hp);
  PrintAt (25,y+2, num, color2);
  sprintf (num, "%d", c->max_hp);
  PrintAt (29,y+2, num, color2);
}
/****************************************************************************
 *                      Clar Status Line
 ***************************************************************************/
void ClearStatusLine()
{
  u8 row;
  for (row = 20; row <=23; ++row) {
    PrintAt (1,row, "                                        ", 0xff);
  }
}
/***************************************************************************
 *                      Calculate Damage
 ***************************************************************************/
u8 CalculateDamage (struct TEntity *c)
{
   return (c->atk*c->atk)/(5*c->defense);
}
/***************************************************************************
 *                      Take Damage
 ***************************************************************************/
void TakeDamage (struct TEntity *c, u8 dmg)
{
   c->hp -= dmg;
}
/****************************************************************************
 *                            Handle Keyboard
 ***************************************************************************/
enum TActions HandleKeyboard (i8 *dx, i8 *dy)
{
  if (cpct_isKeyPressed (Key_I)) {  // i: UP
    *dx = 0; *dy = -1; return PLAYER_MOVED;
  }
  if (cpct_isKeyPressed (Key_K)) {  // k: DOWN
    *dx = 0; *dy = 1; return PLAYER_MOVED;
  }
  if (cpct_isKeyPressed (Key_J)) {  // j: LEFT
    *dx = -1; *dy = 0; return PLAYER_MOVED;
  }
  if (cpct_isKeyPressed (Key_L)) {  // l: RIGHT
    *dx = 1; *dy = 0; return PLAYER_MOVED;
  }
  if (cpct_isKeyPressed (Key_S)) {  // s: WAIT
    return PLAYER_MOVED;
  }
  return NONE;
}
/****************************************************************************
 *                            --- MAIN ---
 ***************************************************************************/
void main(void) {

  // Player and Enemy variables
  struct TEntity player;
  struct TEntity enemy;

  // Player actions
  enum TActions player_action=NONE;

  // Array of 'dirty' flags, signals if entity needs to be drawn
  //i8 dirty[2] = {TRUE, TRUE};
  u8 dirty0 = TRUE;

  // Entities in the game, not used yet, it's buggy!!
  //struct TEntity* entities[MAX_ENTITIES];

  // Current level map
  struct TMap game_map;

  // Damage dealt on attacks
  u8 dmg=0;

  // Move displacement for movement (either player or enemy)
  i8 dx=0, dy=0;

  ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
  cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
  border (1,1); paper (0); pen (1);

  PrintAt (1,5, "      )   ___    _____    )   ___      ", 0xff);
  PrintAt (1,6, "     (__/_____) (, /   ) (__/_____)    ", 0xff);
  PrintAt (1,7, "       /         _/__ /    /           ", 0xff);
  PrintAt (1,8, "      /          /        /            ", 0xff);
  PrintAt (1,9, "     (______) ) /        (______)      ", 0xff);
  PrintAt (1,10, "            _(_/_                      ", 0xff);
  PrintAt (1,11, "           (, /   )                    ", 0xff);
  PrintAt (1,12, "             /__ / ___      _          ", 0xff);

  // Watch out for the extra '\' to print the backslash
  PrintAt (1,13, "          ) /   \\_(_(_/(_(_(/_         ", 0xff);
  PrintAt (1,14, "         (_/       .-/                 ", 0xff);
  PrintAt (1,15, "                  (_/                  ", 0xff);
  PrintAt (10, 18, "PRESS ENTER TO START", 2);
  ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);

  // Wait for ENTER key
  while (!cpct_isKeyPressed (Key_Return)) {
    cpct_scanKeyboard ();
  }

   // Change scene colors
  InitColors();
  // Clear Screen
  cls();

  // Initial values for player/enemy
  CharacterInit (&player, 3, 3,
    SPR_PLAYER, PEN_ENTITY, "Player",
    20, 17, 14, 12);

  CharacterInit (&enemy, 12, 3,
    SPR_GOBLIN, PEN_ENTITY, "Goblin",
    10, 12, 13, 11);

  // Initialize Entities, not used yet, it's buggy!!
  //InitEntities (entities);
  //entities[0] = &player;
  //entities[1] = &enemy;

  // Create map
  MapCreate (&game_map, MAP_WIDTH, MAP_HEIGHT);
  DrawMap(&game_map);
  PrintCharacterStats (&player, 1, 2, 1);

  // Loop forever
  do {
    if (dirty0) {
      PrintAt (PLAY_X+player.px, PLAY_Y+player.py, SPR_FLOOR, PEN_TILE);
      PrintAt (PLAY_X+player.x, PLAY_Y+player.y, player.spr, player.color);
      dirty0 = FALSE;
    }
    PrintAt (PLAY_X+enemy.px, PLAY_Y+enemy.py, SPR_FLOOR, PEN_TILE);
    PrintAt (PLAY_X+enemy.x, PLAY_Y+enemy.y, enemy.spr, enemy.color);

    // Re-scan keyboard
    do
      cpct_scanKeyboard();
      // Moves with i,k,j,l
      // s: Wait 1 turn
      while (!cpct_isKeyPressed (Key_I) && !cpct_isKeyPressed (Key_K) &&
      !cpct_isKeyPressed (Key_J) && !cpct_isKeyPressed (Key_L) &&
      !cpct_isKeyPressed (Key_S));

    // ClearStatusLine();
    // Player actions
    dx = dy = 0;
    do {
      player_action = HandleKeyboard(&dx, &dy);
    } while (!player_action);

    if (player_action == PLAYER_MOVED) {
      player_action = CharacterMove (&game_map, &player, dx, dy) ?
        PLAYER_MOVED : NONE;
    }
    dirty0 = (player_action == PLAYER_MOVED);

    if (player_action) {
    // Enemy actions
      dx = -1; dy = 0;
      CharacterMove (&game_map, &enemy, dx, dy);
    }
  } while (1);
}
