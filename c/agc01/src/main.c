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
//------------------------------------------------------------------------------

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
/****************************************************************************
 * LOCATE, INK, PAPER, BORDER, PEN
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

void main(void) {
   ink (0,0,0); ink (1,0,0); ink (2,0,0);    // Black used palette colors
   cpct_setVideoMode (1);                    // Set Vide Mode 1 (40x25)
   border (0,0); paper (0); pen (1);

   locate (0,4);printf ("      )   ___    _____    )   ___      \n");
   locate (0,5);printf ("     (__/_____) (, /   ) (__/_____)    \n");
   locate (0,6);printf ("       /         _/__ /    /           \n");
   locate (0,7);printf ("      /          /        /            \n");
   locate (0,8);printf ("     (______) ) /        (______)      \n");
   locate (0,9);printf ("            _(_/_                      \n");
   locate (0,10);printf ("           (, /   )                    \n");
   locate (0,11);printf ("             /__ / ___      _          \n");

   // Watch out for the extra '\' to print the backslash
   locate (0,12);printf ("          ) /   \\_(_(_/(_(_(/_         \n");
   locate (0,13);printf ("         (_/       .-/                 \n");
   locate (0,14);printf ("                  (_/                  \n");
   locate (10, 18); pen (2); printf ("PRESS ENTER TO START");
   ink (0, 3,3); ink (1, 6,15); ink (2, 16,16); border (3,3);

   // Loop forever
   while (1);
}
