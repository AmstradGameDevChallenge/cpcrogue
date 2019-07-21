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
   u8 _spr;
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
 *                      Character Initialization
 ***************************************************************************/
void InitializeCharacter (struct TCharacter *c,
   u16 hp, u8 str, u8 destr, u8 refl, u8 spr)
{
   c->_hp = hp;
   c->_str = str;
   c->_destr = destr;
   c->_refl = refl;
   c->_spr = spr;
   c->_atk = 1.5 * c->_str + c->_destr;
   c->_defense = 1.5 * c->_destr + c->_refl;
}
/****************************************************************************
 *                      Display Character Stats
 ***************************************************************************/
void PrintCharacterStats (struct TCharacter *c,
   u8 color1, u8 color2)
{
   pen (color1);printf ("STR "); pen (color2);printf ("[%d] ", c->_str);
   pen (color1);printf ("DES "); pen (color2);printf ("[%d] ", c->_destr);
   pen (color1);printf ("REF "); pen (color2);printf ("[%d]\r\n", c->_refl);

   pen (color1);printf ("ATK "); pen (color2);printf ("[%d] ", c->_atk);
   pen (color1);printf ("DEF "); pen (color2);printf("[%d] ",c->_defense);
   pen (color1);printf (" HP "); pen (color2);printf ("[%d]\r\n", c->_hp);
}
/****************************************************************************
 *                            --- MAIN ---
 ***************************************************************************/
void main(void) {
   /*
    * Player and Enemy variables
    */
   struct TCharacter player, goblin;

   ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
   cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
   border (0,0); paper (0); pen (1);

   locate (0,4);printf ("      )   ___    _____    )   ___      ");
   locate (0,5);printf ("     (__/_____) (, /   ) (__/_____)    ");
   locate (0,6);printf ("       /         _/__ /    /           ");
   locate (0,7);printf ("      /          /        /            ");
   locate (0,8);printf ("     (______) ) /        (______)      ");
   locate (0,9);printf ("            _(_/_                      ");
   locate (0,10);printf ("           (, /   )                    ");
   locate (0,11);printf ("             /__ / ___      _          ");

   // Watch out for the extra '\' to print the backslash
   locate (0,12);printf ("          ) /   \\_(_(_/(_(_(/_         ");
   locate (0,13);printf ("         (_/       .-/                 ");
   locate (0,14);printf ("                  (_/                  ");
   locate (10, 18); pen (2); printf ("PRESS ENTER TO START");
   ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);

   // Wait for ENTER key
   while (!cpct_isKeyPressed (Key_Return)) {
      cpct_scanKeyboard ();
   }

   // Change scene colors
   border (0,0); ink (0, 0,0); ink (1, 25,25); ink (2, 20,20);
   paper (0); pen (2); cls ();

   // Initial values for player/goblin
   InitializeCharacter (&player, 150, 17, 14, 12, '@');
   InitializeCharacter (&goblin, 100, 12, 13, 11, 'g');

   // Show player and goblin stats
   PrintCharacterStats (&player, 1,2);
   PrintCharacterStats (&goblin, 1,2);

   // Loop forever
   while (1);
}
