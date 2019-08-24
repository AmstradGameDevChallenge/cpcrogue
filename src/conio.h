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

///////////////////////////////////////////////////////////////
//       ------ THESE ARE NO LONGER REQUIRED ------
///////////////////////////////////////////////////////////////
//void locate (u8 x, u8 y);
//void ink (u8 tinta, u8 color1, u8 color2);
//inline void border (u8 color1);
//void paper (u8 color1);
//void pen (u8 tinta);


/*! \brief
 * Clears the specified display buffer completely
 *
 * \param pvmem_start Start of video memory buffer to clear
 * \param color Colour pattern to be used for clearing. Typically, a 0x0000
 * is used to fill up all teh screen with 0's (firmware colour 0).
 * Take into account that CPC's memory access is little-endian: this means
 * that using 0x1122 as colour pattern will fill up memory with the sequence
 * 0x22, 0x11, 0x22, 0x11...
 */
inline void clrscr (void *pvmem_start, u16 color)
{
  cpct_memset_f64 ( (void*)pvmem_start, color, 0x4000);
}

/*! \brief
 * Clears a portion of the specified display buffer */
void clrwin (u8 *pvmem_start, u8 cols, u8 rows, u8 color);

/*! \brief
 * Draws a character to the specified position in a screen buffer.*/
void putchar_f (void *pvmem_start, u8 x, u8 y, u8 ch, u8 fg_pen, u8 bg_pen);

/*! \brief
 * Prints a 8 bit value to the specified address in a screen buffer.*/
void PrintU8 (void *pvmem, u8 num, u8 fg_pen, u8 bg_pen);

// Black out the screen so we don't see any draw operations
// Probably this will be obsolete if we implement double buffer
void OffScreen ();

// Display contents of screen
void OnScreen ();