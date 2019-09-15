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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fighter.h"
#include "consts.h"
#include "entity.h"
#include "conio.h"

extern u8 msg[];

///< Count of how many fighters we allocated
u8 num_fighters;

///< Array of fighter components so we use them as we need them
struct TFighter fighters[MAX_FIGHTER_COMPONENTS];

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
void init_fighters()
{
  cpct_memset (fighters, 0, sizeof (fighters));
  num_fighters = 0;
}

/*!
 */
struct TFighter *fighter_create (i8 hp, u16 xp,
  void (*death_fn) (struct TEntity *))
{
  struct TFighter *fighter = NULL;

  if (num_fighters < MAX_FIGHTER_COMPONENTS)
  {
    // Get an empty slot from the fighters array
#ifdef DEBUG
    assert (num_fighters < MAX_FIGHTER_COMPONENTS);
#endif
    fighter = &fighters[num_fighters++];

    // Set the combat attributes
    fighter->max_hp = fighter->hp = hp;
    fighter->xp = xp;

    // Set the death fn. to call when the entity dies
    fighter->death_fn = death_fn;
  }
  // Return the fighter ptr as our new allocated fighter
  return fighter;
}

/*!
 *
 * A fighter component is responsible of attacking actions. It will use the
 * fighter component stats to determine damage and other data needed for an
 * attack. Note that an attack is performed between a *fighter component*
 * and a target *entity*.
 *
 *  \param fighter  Fighter component that will perform the attack
 *  \param target   Entity that will be attacked
 */
void fighter_attack (struct TFighter *fighter,
                     struct TEntity *target)
{
  sprintf (msg, "%s attacks %s", fighter->owner->name, target->name);
  log_msg (msg);

  fighter_take_damage (target->fighter, fighter->owner, 5);
}

/*!
 *
 */
void fighter_take_damage (struct TFighter *fighter,
                          struct TEntity *attacker,
                          i8 dmg)
{
  extern struct TEntity *player;
  extern bool stats_changed;

  fighter->hp -= dmg;

  sprintf (msg, "%s HP: %d/%d",
    fighter->owner->name, fighter->hp, fighter->max_hp);
  log_msg (msg);

  // Update stats if player took damage
  if (fighter->owner == player)
    stats_changed = true;

  // kill entity if hp <= 0
  if (fighter->hp <= 0) {

    // yield xp to player for killing this mob
    if (fighter->owner != player && attacker == player) {
      player->fighter->xp += fighter->xp;
      check_level();
      stats_changed = true;
    }

    // Execute the death action
    if (fighter->death_fn) {
      fighter->death_fn (fighter->owner);
    }
  }
}


/*!
 * On death, most mobs stop moving.
 */
void kill_mob (struct TEntity *mob) {

  sprintf (msg, "%s is dead!", mob->name);
  log_msg (msg);

  mob->fighter  = NULL;
  mob->ai       = NULL;
  sprintf (msg, "dead %s", mob->name);
  strcpy (mob->name, msg);
  mob->spr      = SPR_REMAINS;
}