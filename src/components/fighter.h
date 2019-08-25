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
 * \defgroup fighter
 *
 * \brief Component with fighting habilities
 *
 * Any entity that can fight or be attacked must have a *TFighter* component.
 * It holds any combat related properties and methods like hit points,
 * maximum hit points, defense, attack power, etc. as well as attack
 * and take damage functions.
 *
 */
/**@{*/

/*!
 * \struct  TFighter
 *
 * \brief Combat related component
 */
// Forward declaration of TEntity;
typedef struct TEntity;
typedef struct TFighter {
  struct TEntity *owner;  ///< Entity that owns this component
  i16 max_hp;     ///< Max health
  i16 hp;         ///< Current health
  u8 str;         ///< Current strength
  u8 des;         ///< Current dexterity
  u8 ref;         ///< Current reflexes
  u8 atk;         ///< Current attack
  u8 def;         ///< Current defense
} TFighter;

/*
 ==========================================================================
   ___  _  _ ___  _    _ ____    ____ _  _ _  _ ____ ___ _ ____ _  _ ____
   |__] |  | |__] |    | |       |___ |  | |\ | |     |  | |  | |\ | [__
   |    |__| |__] |___ | |___    |    |__| | \| |___  |  | |__| | \| ___]

 ==========================================================================
*/
void InitFighterComponents();
TFighter *FighterCreate (i16 hp, u8 str, u8 destr, u8 refl);