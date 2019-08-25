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
#ifndef ENTITY_H
#define ENTITY_H

/*!
 * \defgroup entity
 *
 * \brief A generic object to represent players, enemies, items, etc.
 *
 *
 */
/**@{*/

/*!
 * \struct TEntity
 *
 * \brief A generic object to represent players, enemies, items, etc.
 */
typedef struct TFighter;
typedef struct TEntity {
  u8 x, y;      ///< Current position
  u8 px, py;    ///< Previous position
  u8 spr;       ///< ASCII char to draw this entity
  u8 color;     ///< Color to draw this entity
  u8 name[15];  ///< Name to display in messages
  u8 blocks;    ///< TRUE if blocks movement of another entity

  struct TFighter *fighter; ///< A fighter component for combat
} TEntity;

/*!
 * \var List of all entities. This is fixed to MAX_ENTITIES
 */
extern TEntity entities[];

/*!
 * \var Current number of entities
 */
extern u8 num_entities;

void InitEntities();
TEntity *EntityCreate (u8 x, u8 y, u8 spr, u8 color, u8 name[],
  u8 blocks, struct TFighter *fighter);
void EntityMove (TEntity *c, i8 dx, i8 dy);
void EntityAttack (TEntity *e, TEntity *target);
TEntity *GetBlockingEntity (u8 x, u8 y);
void EntityDraw (TEntity *e, u8 left, u8 top);
void EntityDrawEntities(u8 left, u8 top);
void EntityPrintStats (TEntity *e);

#endif