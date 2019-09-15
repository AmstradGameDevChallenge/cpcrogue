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
#include <string.h>
#include <stdbool.h>
#include "consts.h"
#include "entity.h"
#include "components/fighter.h"
#include "components/ai.h"
#include "components/container.h"
#include "components/items.h"
#include "game_map.h"
#include "conio.h"
#include "draw.h"

#ifdef DEBUG
  #include <assert.h>
#endif
// List of entities in our game
struct TEntity entities[MAX_ENTITIES];  // List of entities in game
u8 num_entities;

//---------------------------------------------------------------------------
void init_entities() {
  cpct_memset (entities, 0x00, sizeof (entities));
  num_entities = 0;
}

//---------------------------------------------------------------------------
void entity_draw(struct TEntity *e) {
  putchar_f ((void*)VMEM_MAP, e->x,e->y, e->spr, e->color, PEN_CLEAR);
}

//---------------------------------------------------------------------------
//void entity_erase (struct TEntity *e) {
//  draw_tile (e->px, e->py, PEN_BRIGHT, PEN_CLEAR);
//}

//---------------------------------------------------------------------------
struct TEntity *entity_create (i8 x, i8 y, u8 spr, u8 color, u8 name[],
  struct TFighter   *fighter,
  struct TAI        *ai,
  struct TContainer *container,
  struct TItem      *item)
{
  struct TEntity *e = NULL;

// If DEBUG ensure we didn't reached # entities limit
#ifdef DEBUG
  assert (num_entities < MAX_ENTITIES);
#endif

  // Get a ptr to next available slot in the entities array
  e = &entities[num_entities++];

  e->x = e->px = x;                 // current posX
  e->y = e->py = y;                 // current posY
  e->spr =spr;                      // char used to draw
  e->color = color;                 // foreground color
  cpct_memcpy (e->name, name,       // name
    strlen(name));

  if (fighter)                      // Set the owner of the component
    fighter->owner = e;             // Fighter component if it's a combat
  e->fighter = fighter;             // entity or NULL

  if (ai)                           // Set owner of the ai
    ai->owner = e;                  // AI component if set for intelligent
  e->ai = ai;                       // creatures or NULL

  if (container) {                  // Set owner of the container and
    init_container (container);     // ...initialize it
    container->owner = e;           //
  }
  e->container = container;         // Container if can collect items or NULL

  if (item)                         // Set owner of the item
    item->owner = e;                // Item component if pickable
  e->item = item;                   // or NULL

  // A new created entity is assumed to be in the world
  e->in_world = true;

  return e;
}

//---------------------------------------------------------------------------
void entity_move (struct TEntity *e, i8 dx, i8 dy)  {

  struct TEntity *target = NULL; // Used when searching entities

  // If the tile @ new position blocks movement (i.e: wall) do nothing
  if (!tile_blocks_movement (e->x+dx, e->y+dy)) {

    // ATTACK if there's fighter entity there
    if ((target = get_fighter_at(e->x+dx, e->y+dy) )) {
#ifdef DEBUG
      assert (target);
#endif
      if (target != e)  // Ensure we are not attacking ourselves!
        // Attack target
        fighter_attack (e->fighter, target);
    } // if (get_fighter_at)
    else {
      // No blocking entity, MOVE to the new position
      e->px = e->x;     // Save old positions
      e->py = e->y;
      e->x  = e->x+dx;  // Update to new position
      e->y  = e->y+dy;
    } // else (get_fighter_at)
  } // if (!tile_blocks_movement)
}

//---------------------------------------------------------------------------
/*! \brief
 * Gets the first blocking entity in a tile
 *
 * \param[in] x,y tile position to check for pressence of entity
 */
struct TEntity *get_fighter_at (i8 x, i8 y)
{
  // For each entity created so far...
  for (u8 n=0; n < num_entities; ++n) {
    // If it's a blocking entity and it's @ the query position,
    // we have a match.
    if (entities[n].fighter &&
      entities[n].x == x && entities[n].y == y) {
      return &entities[n];
    } // if
  } // for
  return NULL;
}

//---------------------------------------------------------------------------
/*! \brief
 * Gets the first item entity in a tile
 *
 * \param[in] x,y tile position to check for pressence of entity
 */
struct TEntity *get_item_at (i8 x, i8 y)
{
  // For each entity created so far...
  for (u8 n=0; n < num_entities; ++n) {
    // If it's a blocking entity and it's @ the query position,
    // we have a match.
    if (entities[n].in_world && entities[n].item &&
      entities[n].x == x && entities[n].y == y) {
      return &entities[n];
    } // if
  } // for
  return NULL;
}

//---------------------------------------------------------------------------
void add_to_world (struct TEntity *e, i8 x, i8 y) {

#ifdef DEBUG
  assert (num_entities < MAX_ENTITIES-1);
#endif

  e->x = x;
  e->y = y;
  e->in_world = true;
  //num_entities++;
}

//---------------------------------------------------------------------------
void remove_from_world (struct TEntity *e) {

#ifdef DEBUG
  // First entity is the player. We should never remove it!
  assert (num_entities > 1);
#endif

  e->in_world = false;
  //num_entities--;
}
//---------------------------------------------------------------------------
void check_level()
{
  extern struct TEntity *player;
  u16 level_up_xp = LEVEL_UP_BASE + player->xp_level * LEVEL_UP_FACTOR;

  // See if the player's experience is enough to level up
  if (player->fighter->xp >= level_up_xp) {
    player->xp_level += 1;
    player->fighter->xp -= level_up_xp;
    player->fighter->max_hp += 10;
    player->fighter->hp = player->fighter->max_hp;
  }
}