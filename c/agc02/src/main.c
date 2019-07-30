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
 * Data structures
 ***************************************************************************/
struct TCharacter {
  u8 x, y;
  u8 spr[2];
  u8 color;
  u8 name[15];
  u16 hp;
  u8 str;
  u8 destr;
  u8 refl;
  u16 atk;
  u16 defense;
};
struct TTile {
  u8 blocked;
};
struct TRect {
  u8 x1;
  u8 y1;
  u8 x2;
  u8 y2;
};
struct TMap {
  u8 width;
  u8 height;
  struct TTile tiles[MAP_HEIGHT][MAP_WIDTH];
};

/****************************************************************************
 * Map fns
 ***************************************************************************/
void map_create (struct TMap *map, u8 width, u8 height)
{

  u8 j,i;
  map->width = width;
  map->height = height;
  for (i=0; i!=map->height; ++i)
    for (j=0; j!=map->width; ++j)
      map->tiles[i][j].blocked = FALSE;

  // Tiles are referenced first vertical (Y), then horizontal (X)
  map->tiles[12][3].blocked = TRUE;
  map->tiles[3][10].blocked = TRUE;
}

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
 *                      Character Initialization
 ***************************************************************************/
void InitializeCharacter (struct TCharacter *c,
   u8 x, u8 y, u8 spr[], u8 color, u8 name[],
   u16 hp, u8 str, u8 destr, u8 refl)
{
  c->x = x; c->y = y;
  strcpy (c->spr, spr);
  c->color = color;
  strcpy (c->name, name);

  c->hp = hp;
  c->str = str;
  c->destr = destr;
  c->refl = refl;

  c->atk = 1.5 * c->str + c->destr;
  c->defense = 1.5 * c->destr + c->refl;

}
/****************************************************************************
 *                      Initialize Entities
 ***************************************************************************/
void InitEntities (struct TCharacter* entities[])
{
  i8 i=MAX_ENTITIES-1;
  do {
    entities[i--] = NULL;
  } while (i != 0);
  entities[0] = NULL;
}
/****************************************************************************
 *                      Draw Map
 ***************************************************************************/
void draw_map (struct TMap *map)
{
  int i,j;
  u8 is_wall;

  // Draw Map
  for (i=0; i!=map->height; ++i) {
    for (j=0; j!=map->width; ++j) {
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

void draw_entities (struct TCharacter* entities[])
{
  struct TCharacter* e;

  u8 i = 0;
  while ( (e = entities[i++]) != NULL ) {
    PrintAt (PLAY_X+e->x, PLAY_Y+e->y, e->spr, e->color);
  }
}
*/
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
void PrintCharacterStats (struct TCharacter *c, u8 y,
   u8 color1, u8 color2)
{
  char num[10];
  PrintAt (10,y, c->name, color1); PrintAt (21,y, c->spr, color2);
  PrintAt (1, y+1, "STR ",color1);
  PrintAt (10,y+1, "DES ",color1);
  PrintAt (20,y+1, "REF ",color1);
  sprintf (num, "[%d] ", c->str);
  PrintAt (5,y+1, num, color2);
  sprintf (num, "[%d] ", c->destr);
  PrintAt (15,y+1, num, color2);
  sprintf (num, "[%d] ", c->refl);
  PrintAt (25,y+1, num, color2);

  PrintAt (1, y+2, "ATK ", color1);
  PrintAt (10,y+2, "DEF ", color1);
  PrintAt (20,y+2, " HP ", color1);
  sprintf (num, "[%d] ", c->atk);
  PrintAt (5,y+2, num, color2);
  sprintf (num, "[%d] ",c->defense);
  PrintAt (15,y+2, num, color2);
  sprintf (num, "[%d]\r\n", c->hp);
  PrintAt (25,y+2, num, color2);
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
u8 CalculateDamage (struct TCharacter *c)
{
   return (c->atk*c->atk)/(5*c->defense);
}
/***************************************************************************
 *                      Take Damage
 ***************************************************************************/
void TakeDamage (struct TCharacter *c, u8 dmg)
{
   c->hp -= dmg;
}
/****************************************************************************
 *                            --- MAIN ---
 ***************************************************************************/
void main(void) {

  // Player and Enemy variables
  struct TCharacter player;
  struct TCharacter goblin;

  // Entities in the game, not used yet, it's buggy!!
  //struct TCharacter* entities[MAX_ENTITIES];

  // Current level map
  struct TMap game_map;

  // Damage dealt on attacks
  u8 dmg;

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

  // Initial values for player/goblin
  InitializeCharacter (&player, 3, 3,
    SPR_PLAYER, PEN_ENTITY, "Player",
    150, 17, 14, 12);

  InitializeCharacter (&goblin, 12, 3,
    SPR_GOBLIN, PEN_ENTITY, "Goblin",
    100, 12, 13, 11);

  // Initialize Entities, not used yet, it's buggy!!
  //InitEntities (entities);
  //entities[0] = &player;
  //entities[1] = &goblin;

  // Create map
  map_create (&game_map, MAP_WIDTH, MAP_HEIGHT);
  draw_map(&game_map);

  // Loop forever
  do {
    PrintCharacterStats (&player, 1, 1, 1);
    PrintAt (PLAY_X+player.x, PLAY_Y+player.y, player.spr, player.color);
    PrintAt (PLAY_X+goblin.x, PLAY_Y+goblin.y, goblin.spr, goblin.color);

    // Re-scan keyboard

    cpct_scanKeyboard();
    while (!cpct_isKeyPressed (Key_A)) {
       cpct_scanKeyboard();
    }

    ClearStatusLine();
    // Player actions
    if (cpct_isKeyPressed (Key_A)) {
      dmg=CalculateDamage (&player);
      TakeDamage (&goblin, dmg);
      locate (1,21);pen (1);printf ("goblin takes ");
      pen (3); printf ("%d",dmg);
      pen (1); printf (" hit points");
    }
    // Enemy actions
    if (cpct_rand() < 64) {
      dmg=CalculateDamage (&goblin);
      TakeDamage (&player, dmg);
      locate (1,22);pen (1);printf ("you take ");
      pen (3); printf ("%d", dmg);
      pen (1); printf (" hit points from goblin");
    }

  } while (1);
}
