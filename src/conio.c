//-----------------------------LICENSE NOTICE--------------------------------
//  This file is part of CPCRogue: An Amstrad CPC rogue like game
//  Copyright (C) 2019 Andrés Mata Bretón (@FlautinesMata)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
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
#include "conio.h"
#include "consts.h"
//#include <stdio.h>

//TConMsg con_messages[];
u8 num_messages;


void clr_log() {
  clrwin ((void*)VMEM_LOG, LOG_W, 4, PEN_CLEAR);
}

void clr_stats() {
  clrwin ((void*)VMEM_STATS_XP, STATS_W, 10, PEN_CLEAR);
}

/*!
 * Starting at given memory address (usually video memory) it clears
 * the specified cols x rows section.
 *
 *  \param pvmem_start  Address of the start cell to clear
 *  \param cols         Width in bytes of the portion to clear
 *  \param rows         Height in characters, not bytes or pixels.
 *                      There are 25 rows in Mode 1
 *  \param color Color pattern to use as byte pattern, not pen color
 */
void clrwin (u8 *pvmem_start, u8 cols, u8 rows, u8 color)
{
  for (u8 i=0; i != rows; ++i) {
    for (u8 line=0; line != 8; ++line) {
      cpct_memset (pvmem_start+i*0x50+line*0x800, color, cols);
    }
  }
  num_messages = 0;
}

/*
 * It calls cpct_drawCharM1_f to draw a character very fast at a specified.
 * In addition, foreground and background colors are used to color the char.
 *
 * \param vmem Start of video memory buffer to draw
 * \param x,y  X,Y coordinates (in characters) where to draw
 * \param ch   Character to draw
 * \param fg_pen Foreground color to use to draw the char
 * \param bg_pen Background color to use to draw the char
 */
void putchar_f (void *pvmem_start, u8 x, u8 y, u8 ch, u8 fg_pen, u8 bg_pen)
{
  void *pvdest = cpct_getScreenPtr (pvmem_start, x*2, y*8);

  cpct_drawCharM1_f (pvdest, fg_pen, bg_pen, ch);
}

void log_msg (char *msg)
{
  if (num_messages>2) {
    cpct_drawStringM1_f ("Press RETURN", (void*)(VMEM_LOG+3*0x50),
    PEN_CLEAR, PEN_BRIGHT);

    wait_for_key (Key_Return);
    clr_log();

    num_messages = 0;
  } // if

  cpct_drawStringM1_f (msg, (void*)(VMEM_LOG+num_messages*0x50),
    PEN_BRIGHT, PEN_CLEAR);
  num_messages++;
}

void wait_for_key(cpct_keyID key) {

  cpct_scanKeyboard();
  while (!cpct_isKeyPressed(key)) {
    cpct_scanKeyboard();
  }
  //cpctm_produceHalts (100);
}