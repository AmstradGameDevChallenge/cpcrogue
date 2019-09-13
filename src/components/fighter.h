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
typedef struct TEntity;

struct TFighter{
  struct TEntity *owner;  ///< Entity that owns this component
  i8 max_hp;             ///< Max health
  i8 hp;                 ///< Current health

  ///< Death fn. to call when entity dies
  void (*death_fn)(struct TEntity *);
};

void init_fighters();
struct TFighter *fighter_create (i8 hp,
  void (*death_fn) (struct TEntity *));

/*! \brief
 *
 * Take dmg points of damage
 *
 * \returns true if fighter 'hp' <= 0
 */
void fighter_take_damage (struct TFighter *fighter, i8 dmg);

/*! \brief
 *
 *  Perform an attack action to an entity!
 *
 * \returns true if fighter 'hp' <= 0
 */
void fighter_attack (struct TFighter *fighter, struct TEntity *target);

void kill_mob (struct TEntity *mob);