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
#include <stdbool.h>
#include "constants.h"
#include "fighter.h"
#include "user_interface.h"


///< How many fighter components we allocate, by default we allocate as many
/// as max entities
#define MAX_FIGHTER_COMPONENTS  MAX_ENTITIES

///< Count of how many fighters we allocated
u8 num_fighters;

///< Array of fighter components so we use them as we need them
TFighter fighters[MAX_FIGHTER_COMPONENTS];

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

/*!
 *
 * A fighter component is responsible of attacking actions. It will use the
 * fighter component stats to determine damage and other data needed for an
 * attack. Note that an attack is performed between a *fighter component*
 * and a target *entity*.
 *
 *  \param fighter Fighter component that will perform the attack
 *  \param target  Entity that will be attacked
 */
u8 FighterAttack (TFighter *fighter, struct TEntity *target)
{
  u8 dmg;
  u8 msg[38] = "";

  dmg = EntityCalculateDamage (fighter);

  /*strcat (msg, fighter->owner->name);
  strcat (msg, " attacks ");
  strcat (msg, target->name);
  */
  sprintf (msg, "%s attacks %s", fighter->owner->name, target->name);
  LogMessage (msg, 0);

  return FighterTakeDamage (target->fighter, dmg);
}

/*!
 *
 */
u8 FighterTakeDamage (TFighter *fighter, u8 dmg)
{
  u8 msg[38] = "";
  fighter->hp -= dmg;

  if (fighter->hp <= 0)
    return true;

  sprintf (msg, "and hits for %d damage", dmg);
  LogMessage (msg, 1);

  return false;
}

//===========================================================================
//===========================================================================
/***
 *       ___  ____ _ _  _ ____ ___ ____
 *       |__] |__/ | |  | |__|  |  |___
 *       |    |  \ |  \/  |  |  |  |___
 *    ____ _  _ _  _ ____ ___ _ ____ _  _ ____
 *    |___ |  | |\ | |     |  | |  | |\ | [__
 *    |    |__| | \| |___  |  | |__| | \| ___]
 *
 */
//===========================================================================
//===========================================================================
/*!
 *
 */
u8 EntityCalculateDamage (TFighter *fighter)
{
  u8 dmg = fighter->atk >> 2;
  u8 r = (cpct_rand() * 7/255) - 3;
  dmg += r;
  return (dmg < 127 ? dmg : dmg+3);
}
