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
#include "consts.h"
#include "entity.h"
#include "items.h"
#include "container.h"
#include "conio.h"


extern u8 msg[];
///< Count of how many items we allocated
u8 num_items;

///< Array of item components so we use them as we need them
struct TItem items[MAX_ITEMS];

//---------------------------------------------------------------------------
void init_items()
{
  cpct_memset (items, 0, sizeof (items));
  num_items = 0;
}
//---------------------------------------------------------------------------

struct TItem *item_create(bool is_gold)
{
  struct TItem *item=NULL;
  if (num_items < MAX_ITEMS) {
    item = &items[num_items++];
    item->is_gold = is_gold;
    if (is_gold) {
      item->value = 25;
    }
  }
  return item;
}

//---------------------------------------------------------------------------
void pick_up (struct TItem *item, struct TEntity *entity)
{
  if (item->is_gold) {
    take_gold(item);
  }
  else {
    if (entity->container) {
        if (entity->container->num_items+1 > MAX_INVENTORY_ITEMS)
          log_msg_ext ("\477\11\10Inventory full!");

      else {
        sprintf (msg, "\477\11\10Picking up \477\10\11%s",
          item->owner->name);
        log_msg_ext (msg);
        append_to_container (entity->container, item->owner);
        remove_from_world (item->owner);
        item->container = entity->container;
      } // else
    } // if (container)
  } // else (item->is_gold)

}

//---------------------------------------------------------------------------
void drop (struct TItem *item, i8 x, i8 y) {

  add_to_world (item->owner, x,y);
  remove_from_container (item->container, item->owner);

  sprintf (msg, "\477\11\10Item \477\10\11%s\477\11\10 dropped",
    item->owner->name);
  log_msg_ext (msg);
}

//---------------------------------------------------------------------------
void take_gold(struct TItem *item_gold) {
  extern struct TEntity *player;
  extern bool stats_changed;

  player->item->value += item_gold->value;
  sprintf (msg, "\477\11\10You got \477\10\11%d\477\11\10 gold",
    item_gold->value);
  log_msg_ext (msg);
  remove_from_world (item_gold->owner);
  stats_changed = true;
}

//---------------------------------------------------------------------------
// Use an item by producing an effect and removing it.
void use(struct TItem *item) {

  if (item->use_fn) {
    item->use_fn(item->container->owner, item->value);
    remove_from_container (item->container, item->owner);
  }

}