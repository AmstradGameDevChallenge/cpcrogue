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
/****************************************************************************
 * Data structures
 ***************************************************************************/
struct TCharacter {
   u16 _hp;
   u8 _str;
   u8 _destr;
   u8 _refl;
   u16 _atk;
   u16 _defense;
   u8 _spr[2];
   u8 name[15];
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
void cls ()
{
   putchar (FF);
}
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
   u16 hp, u8 str, u8 destr, u8 refl, u8 spr,
   char name[])
{
   c->_hp = hp;
   c->_str = str;
   c->_destr = destr;
   c->_refl = refl;
   c->_spr[0] = spr; c->_spr[1] = '\0';
   c->_atk = 1.5 * c->_str + c->_destr;
   c->_defense = 1.5 * c->_destr + c->_refl;
   strcpy (c->name, name);
}
/****************************************************************************
 *                      Display Character Stats
 ***************************************************************************/
void PrintCharacterStats (struct TCharacter *c, u8 y,
   u8 color1, u8 color2)
{
  char num[10];
  PrintAt (10,y, c->name, color1); PrintAt (21,y, c->_spr, color2);
  PrintAt (1, y+1, "STR ",color1);
  PrintAt (10,y+1, "DES ",color1);
  PrintAt (20,y+1, "REF ",color1);
  sprintf (num, "[%d] ", c->_str);
  PrintAt (5,y+1, num, color2);
  sprintf (num, "[%d] ", c->_destr);
  PrintAt (15,y+1, num, color2);
  sprintf (num, "[%d] ", c->_refl);
  PrintAt (25,y+1, num, color2);

  PrintAt (1, y+2, "ATK ", color1);
  PrintAt (10,y+2, "DEF ", color1);
  PrintAt (20,y+2, " HP ", color1);
  sprintf (num, "[%d] ", c->_atk);
  PrintAt (5,y+2, num, color2);
  sprintf (num, "[%d] ",c->_defense);
  PrintAt (15,y+2, num, color2);
  sprintf (num, "[%d]\r\n", c->_hp);
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
   return (c->_atk*c->_atk)/(5*c->_defense);
}
/***************************************************************************
 *                      Take Damage
 ***************************************************************************/
void TakeDamage (struct TCharacter *c, u8 dmg)
{
   c->_hp -= dmg;
}
/****************************************************************************
 *                            --- MAIN ---
 ***************************************************************************/
void main(void) {
  /*
  * Player and Enemy variables
  */
  struct TCharacter player, goblin;
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
  border (0,0); ink (0, 0,0); ink (1, 25,25); ink (2, 20,20);
  paper (0); pen (2); cls ();

  // Initial values for player/goblin
  InitializeCharacter (&player, 150, 17, 14, 12, '@', "Player");
  InitializeCharacter (&goblin, 100, 12, 13, 11, 'g', "Goblin");

  // Loop forever
  do {
    locate (1,1);
    // Show player and goblin stats
    PrintCharacterStats (&player, 1, 1,2);
    PrintCharacterStats (&goblin, 5, 1,2);

    // Ask for action
    PrintAt (1,20, "ACTION? ", 1);
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
