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
#include "input.h"
#include "entity.h"
#include "components/items.h"
#include "components/container.h"
#include "conio.h"


extern struct TEntity *player;
extern u8 msg[];
/****************************************************************************
 *                            Handle Keyboard
 ***************************************************************************/
TAction handle_keys (i8 *dx, i8 *dy)
{
  extern bool fov_changed;

  // Get keyboard state
  cpct_scanKeyboard();

  // UP
  if (cpct_isKeyPressed (Key_CursorUp)) {
    *dx = 0; *dy = -1;
    fov_changed = true;
    return PLAYER_MOVE;
  }

  // DOWN
  if (cpct_isKeyPressed (Key_CursorDown)) {
    *dx = 0; *dy = 1;
    fov_changed = true;
    return PLAYER_MOVE;
  }

  // LEFT
  if (cpct_isKeyPressed (Key_CursorLeft)) {
    *dx = -1; *dy = 0;
    fov_changed = true;
    return PLAYER_MOVE;
  }

  // RIGHT
  if (cpct_isKeyPressed (Key_CursorRight)) {
    *dx = 1; *dy = 0;
    fov_changed = true;
    return PLAYER_MOVE;
  }

  // s: WAIT
  if (cpct_isKeyPressed (Key_S)) {
    fov_changed = true;
    return PLAYER_WAIT;
  }

  // g: GET
  // TODO: Menu to choose what to pick up if >1 object in tile
  if (cpct_isKeyPressed (Key_G)) {
    struct TEntity *entity = get_item_at (player->x, player->y);

    if (entity) {
      pick_up (entity->item, player);
    }
  }

  // d: DROP
  // TODO: Menu to select what to drop if carrying >1 items
  //       For now, it will drop the last picked up item
  if (cpct_isKeyPressed (Key_D)) {
    if (player->container->num_items > 0) {
      drop (player->container->inventory[player->container->num_items-1]->item,
        player->x, player->y);
    }
  }

  // i: INVENTORY
  if (cpct_isKeyPressed (Key_I)) {
    for (u8 i=0; i<player->container->num_items; ++i) {
      sprintf (msg, "\477\11\10%c\477\12\10 - %s",
        'a'+i, player->container->inventory[i]->name);
      log_msg_ext (msg);
    }
  }

  // u: USE
  if (cpct_isKeyPressed (Key_U)) {
    if (player->container->num_items > 0) {
      struct TEntity *e;
      e= player->container->inventory[player->container->num_items-1];
      use (e->item);
    }
  }

  if (cpct_isAnyKeyPressed_f())
    cpctm_produceHalts (50);
  return NONE;
}