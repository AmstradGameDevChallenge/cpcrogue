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
#include <assert.h>
#include "constants.h"
#include "ai.h"


// forward declaration
void LogMessage (char *msg, u8 row);

TAI ai_components[MAX_AI_COMPONENTS];
u8 num_ai_components;


//===========================================================================
//===========================================================================
/***
 *       ___  _  _ ___  _    _ ____
 *       |__] |  | |__] |    | |
 *       |    |__| |__] |___ | |___
 *    ____ _  _ _  _ ____ ___ _ ____ _  _ ____
 *    |___ |  | |\ | |     |  | |  | |\ | [__
 *    |    |__| | \| |___  |  | |__| | \| ___]
 *
 */
//===========================================================================
//===========================================================================
void InitAIComponents()
{
  cpct_memset (ai_components, 0, sizeof (ai_components));
  num_ai_components = 0;
}

TAI *BasicAI_Create ()
{
  TAI *ai = NULL;

  if (num_ai_components < MAX_AI_COMPONENTS)
  {
    // Get an empty slot from the ai array
    assert (num_ai_components < MAX_AI_COMPONENTS);
    ai = &ai_components[num_ai_components++];

    // Set the AI TakeTurn function
    ai->TakeTurn = BasicAI_TakeTurn;

    // Return the ai ptr as our new allocated ai
  }
  return ai;

}

void BasicAI_TakeTurn (TAI *this)
{
  LogMessage ("I will destroy you!", 1);
}