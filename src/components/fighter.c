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
#include <assert.h>
#include <stdio.h>
#include "constants.h"
#include "fighter.h"

// How many fighter components we allocate, by default we allocate as many
// as max entities
#define MAX_FIGHTER_COMPONENTS  MAX_ENTITIES

// Count of how many fighters we allocated
u8 num_fighters;

// Array of fighter components so we use them as we need them
TFighter fighters[MAX_FIGHTER_COMPONENTS];


void InitFighterComponents()
{
  cpct_memset (fighters, 0, sizeof (fighters));
  num_fighters = 0;
}

/*!
 */
TFighter *FighterCreate (i16 hp, u8 str, u8 destr, u8 refl)
{
  TFighter *fighter = NULL;

  if (num_fighters < MAX_FIGHTER_COMPONENTS)
  {
    // Get an empty slot from the fighters array
    assert (num_fighters < MAX_FIGHTER_COMPONENTS);
    fighter = &fighters[num_fighters++];

    // Set the combat attributes
    fighter->max_hp = hp;
    fighter->hp = hp;
    fighter->str = str;
    fighter->des = destr;
    fighter->ref = refl;

    fighter->atk = (str  + destr)>>1;
    fighter->def = (destr + refl)>>1;

    // Return the fighter ptr as our new allocated fighter
  }
  return fighter;
}