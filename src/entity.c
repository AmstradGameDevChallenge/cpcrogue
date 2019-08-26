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
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "logo.h"
#include "components/fighter.h"
#include "entity.h"
#include "constants.h"
#include "conio.h"
#include "fov.h"
#include "user_interface.h"
#include "game_map.h"

// List of entities in our game
TEntity entities[MAX_ENTITIES];  // List of entities in game
u8 num_entities;

void InitEntities()
{
  cpct_memset (entities, 0, sizeof (entities));
  num_entities = 0;
}


/****************************************************************************
 *               Create en entity with given values
 ***************************************************************************/
TEntity *EntityCreate (u8 x, u8 y, u8 spr, u8 color, u8 name[],
  u8 blocks, TFighter *fighter)
{
  TEntity *e = NULL;
  // We reached max. allowed entities
  assert (num_entities < MAX_ENTITIES);

  // Get a ptr to next available slot in the entities array
  e = &entities[num_entities++];

  e->x = e->px = x;                 // current posX
  e->y = e->py = y;                 // current posY
  e->spr =spr;                      // char used to draw
  e->color = color;                 // foreground color
  cpct_memcpy (e->name, name, 15);  // name
  e->blocks = blocks;               // blocks other entities?

  if (fighter)
    fighter->owner = e;             // Set the owner of the component

  e->fighter = fighter;             // Fighter component if it's a combat
                                    // entity or NULL

  // Mark this tile as occupied
  game_map.tiles[y][x].t_flags |= HAS_ENTITY;
  return e;
}
/****************************************************************************
 *                    Draw a single entity
 ***************************************************************************/
void EntityDraw (TEntity *e, u8 left, u8 top)
{
  u8 x, y, color, spr;
  x = e->x - left;
  y = e->y - top;
  color = e->color;
  spr = e->spr;

  if (x > 127 || x > VIEW_WIDTH-1 || y > 127 || y > VIEW_HEIGHT-1) return;

  // Draw the entity only if it's visible
  if (isVisible (e->x,e->y))
    putchar_f (VMEM_MAP, x,y, spr, color, PEN_CLEAR);
}

void EntityErase (TEntity *e, u8 left, u8 top)
{
  u8 px, py, view_x, view_y;
  TTile *erasing_tile;
  u8 is_wall, visible;

  px = e->px;
  py = e->py;
  if (px < left || py < top) return;
  view_x = px - left;
  view_y = py - top;

  erasing_tile = &game_map.tiles[py][px];
  visible = isVisible (px, py);
  is_wall = erasing_tile->t_flags & BLOCKED;

  // The previous tile we are "erasing" no longer has an entity
  game_map.tiles[py][px].t_flags &= ~HAS_ENTITY;
  MapDrawTile (erasing_tile, view_x, view_y, px, py, visible, is_wall);
}
/****************************************************************************
 *                      Move entity to new position
 ***************************************************************************/
void EntityMove (TEntity *e, i8 dx, i8 dy)
{
  // The old position is now free
  //game_map.tiles[e->y][e->x].t_flags &= ~HAS_ENTITY;
  e->px = e->x;     // Save old positions
  e->py = e->y;
  e->x  = e->x+dx;   // Update to new position
  e->y  = e->y+dy;

  // The new position is now occupied
  game_map.tiles[e->y][e->x].t_flags |= HAS_ENTITY;
}
/****************************************************************************
 *           Get Damage points from entity stats
 ***************************************************************************/
u8 EntityCalculateDamage (TEntity *e)
{
/*
  u8 dmg = e->atk >> 2;
  u8 r = (cpct_rand() * 7/255) - 3;
  dmg += r;
  return (dmg < 127 ? dmg : dmg+3);
*/
}
/****************************************************************************
 *           Take dmg points of damage
 ***************************************************************************/
void EntityTakeDamage (TEntity *e, u8 dmg)
{
  /*
  e->hp -= dmg;

  PrintAt (STATUS_X,STATUS_Y+1, e->name, PEN_BRIGHT);
  PrintAt (STATUS_X+7,STATUS_Y+1, "takes     ", PEN_NORMAL);
  PrintU8 (dmg, STATUS_X+13,STATUS_Y+1, PEN_BRIGHT);
  PrintAt (STATUS_X+16,STATUS_Y+1, "points of damage", PEN_NORMAL);
  */
}
/****************************************************************************
 *                      Attack 'target'
 ***************************************************************************/
void EntityAttack (TEntity *e, TEntity *target)
{
  u8 dmg;
  u8 msg[38] = "";
  // Show action in log window
/*
  PrintAt (STATUS_X,STATUS_Y, e->name, PEN_BRIGHT);
  PrintAt (STATUS_X+8,STATUS_Y, "attacks", PEN_NORMAL);
  PrintAt (STATUS_X+16,STATUS_Y, target->name, PEN_BRIGHT);

  dmg = EntityCalculateDamage (e);
  EntityTakeDamage (target, dmg);
*/
  strcat (msg, e->name);
  strcat (msg, " attacks ");
  strcat (msg, target->name);
  LogMessage (msg, 0);
}
/****************************************************************************
 *           Get first blocking entity at given position
 ***************************************************************************/
TEntity *GetBlockingEntity (u8 x, u8 y)
{
  // For each entity created so far...
  for (u8 n=0; n < num_entities; ++n) {
    // If it's a blocking entity and it's @ the query position,
    // we have a match.
    if (entities[n].blocks &&
      entities[n].x == x && entities[n].y == y) {
      return &entities[n];
    } // if
  } // for
  return NULL;
}
/****************************************************************************
 *                      Draw all entities in array
 ***************************************************************************/
void EntityDrawEntities (u8 left, u8 top)
{
  TEntity *e = &entities[0];

  for (u8 eid = 0; eid < num_entities; ++eid, ++e) {
    EntityDraw (e, left, top);
  }
}
void EntityEraseEntities (u8 left, u8 top)
{
  TEntity *e = &entities[0];

  for (u8 eid = 0; eid < num_entities; ++eid, ++e) {
    if (e->px != e->x || e->py != e->y)
    EntityErase (e, left, top);
  }
}