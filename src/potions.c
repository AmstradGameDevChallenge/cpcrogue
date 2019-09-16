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
#include <stdbool.h>
#include "potions.h"
#include "aux_math.h"
#include "conio.h"
#include "entity.h"
#include "components/fighter.h"

void cast_heal(struct TEntity *target, u8 value) {
  extern u8 msg[];
  extern struct TEntity *player;
  extern bool stats_changed;

  target->fighter->hp = min (target->fighter->hp + value,
                              target->fighter->max_hp);

  sprintf (msg, "\477\11\10%s healed for \477\12\10%d \477\11\10hp",
    target->name, value);
  log_msg_ext (msg);


  if (target == player)
    stats_changed = true;
}