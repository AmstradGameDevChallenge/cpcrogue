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
#include "constants.h"
#include "input_handler.h"


/****************************************************************************
 *                            Handle Keyboard
 ***************************************************************************/
TAction HandleKeyboard (i8 *dx, i8 *dy)
{
  if (cpct_isKeyPressed (Key_I)) {  // i: UP
    *dx = 0; *dy = -1; return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_K)) {  // k: DOWN
    *dx = 0; *dy = 1; return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_J)) {  // j: LEFT
    *dx = -1; *dy = 0; return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_L)) {  // l: RIGHT
    *dx = 1; *dy = 0; return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_S)) {  // s: WAIT
    return PLAYER_MOVE;
  }
  if (cpct_isKeyPressed (Key_N)) {  // s: WAIT
    return NEW_LEVEL;
  }
  return NONE;
}