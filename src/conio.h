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

/*
struct TConMsg {
  u8 text[38];
  u8 fg_pen;
  u8 bg_pen;
};
*/

/*! \brief
 * Clears a portion of the specified display buffer */
void clrwin (u8 *pvmem_start, u8 cols, u8 rows, u8 color);

/*! \brief
 * Clears the log area */
void clr_log();

/*! \brief
 * Draws a character to the specified position in a screen buffer.*/
void putchar_f (void *pvmem_start, u8 x, u8 y, u8 ch, u8 fg_pen, u8 bg_pen);

void log_msg (char *msg);

void wait_for_key(cpct_keyID key);
