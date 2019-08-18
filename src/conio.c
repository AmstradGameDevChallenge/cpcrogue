//-----------------------------LICENSE NOTICE--------------------------------
//  This file is part of CPCRogue: An Amstrad CPC rogue like game
//  Copyright (C) 2019 Andrés Mata Bretón (@FlautinesMata)
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
//---------------------------------------------------------------------------
#include <cpctelera.h>
#include <stdio.h>
#include "constants.h"
#include "conio.h"


/****************************************************************************
 * Video fn: LOCATE, INK, PAPER, BORDER, PEN, CLS
 ***************************************************************************/
inline void cls ()
{
  putchar (FF);
}
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
inline void border (u8 color1)
{
  putchar (GS);
  putchar (color1); putchar (color1);
}
/****************************************************************************
 *                      PrintAt
 ***************************************************************************/
void PrintAt (u8 x, u8 y, char text[], u8 color)
{
  u8 i = 0, ch;

  locate (x, y);
  if (color != 0xff) pen (color);
  while ( (ch=text[i++]) )
    putchar(ch);

}
/****************************************************************************
 *                      PrintU8
 ***************************************************************************/
void PrintU8 (u8 num, u8 x, u8 y, u8 color)
{
  u8 str[4];
  sprintf (str, "%d", num);
  PrintAt (x,y, str, color);
}
/****************************************************************************
 *  OffScreen
 ***************************************************************************/
void OffScreen ()
{
  ink (0, INK_BG,INK_BG);
  ink (1, INK_BG,INK_BG);
  ink (2, INK_BG,INK_BG);
  ink (3, INK_BG,INK_BG);

  border (0); paper (0);
}
/****************************************************************************
 *
 ***************************************************************************/
void OnScreen ()
{
  ink (0, INK_BG,INK_BG);
  ink (1, INK_DARK, INK_DARK);
  ink (2, INK_BRIGHT, INK_BRIGHT);
  ink (3, INK_NORMAL, INK_NORMAL);

  border (0); paper (0);
}