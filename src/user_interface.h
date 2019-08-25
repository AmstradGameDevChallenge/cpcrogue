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
/*!
 * \defgroup user_interface
 *
 * \brief Routines to draw visible game elements
 *
 * The functions in this module are responsible for drawing different
 * elements of the game:
 *
 *  - HUD decorations
 *  - Map world
 *  - Status window (messages)
 *  - Stats window
 *
 */
/**@{*/

/*! \brief Draws the HUD decorations */
void DrawHUD (void *pvmem_start);

/*! \brief Draws the *stats* window */
void PrintStats (TEntity *e);

/*! \brief Displays a 'loading...' message in the status window */
void DisplayLoading ();

/*! \brief
 * Clears the status message window up to *nrows* lines.
 */
void ClearStatus (u8 nrows);

/*! \brief
 * Displays a message in the STATUS window
 */
void LogMessage (char *msg, u8 row);

/*! \brief Draw the visible elements in the game */
void DrawGame (TEntity *player, u8 left, u8 top, u8 draw_flags);