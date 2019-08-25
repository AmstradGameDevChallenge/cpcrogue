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
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "constants.h"
#include "entity.h"
#include "game_map.h"
#include "fov.h"
#include "user_interface.h"

/*
 *
 */
void NewGame (TEntity **player)
{
  *player = EntityCreate (0, 0,
    SPR_PLAYER, PEN_BRIGHT,
    "Thorbag", true,
     20, 17, 14, 12);
  MapCreate (MAP_WIDTH, MAP_HEIGHT, *player);

  ComputeLOS ((*player)->x, (*player)->y, FOV_RADIUS);
}

/*
 *
 */
void GameDraw (TEntity *player,
  u8 *fov_changed, u8 *view_updated, u8 *left, u8 *top, u8 draw_flags)
{
  // Check if we need to recompute field of view
  if (*fov_changed) {
    ComputeLOS (player->x, player->y, FOV_RADIUS);
    MapDraw (*left, *top, VIEW_WIDTH, VIEW_HEIGHT, player);
    *fov_changed = false;
  }

  if (*view_updated) {
    *view_updated = false;
    ComputeLOS (player->x, player->y, FOV_RADIUS);
    GetView (player, left, top, VIEW_WIDTH, VIEW_HEIGHT);
    DrawGame (player, *left, *top, draw_flags);
  }
  EntityDrawEntities(*left, *top);
}

void
GameDoPlayerTurn (TEntity *player, u8 dx, u8 dy, u8 left, u8 top,
  u8 *log_is_full, u8 *view_updated, u8 *fov_changed)
{
  TEntity *target = NULL; // Used when searching entities
  u8 new_x, new_y;        // Temporary new positions

  new_x = player->x+dx;
  new_y = player->y+dy;

  // If the tile @ new position blocks movement (i.e: wall) do nothing
  if (!MapIsBlocked (new_x, new_y)) {

    // If it's free, check if there's a blocking entity there
    if ( (target = GetBlockingEntity (new_x, new_y)) ) {
      /*
       * Blocking entity in the new position
       * Attack it!
       *
       */
      assert (target);
      if (target != player) EntityAttack (player, target);
      *log_is_full = true;
    } // if (GetBlockingEntity)

    else {
      /*
       * Not blocking entity in the new position
       *
       * Before moving, check if we are on the viewport limits
       *
       */
      if (new_x <= left || new_y <= top ||
        new_x > left+VIEW_WIDTH-1 ||
        new_y > top+VIEW_HEIGHT-1) {

        // We are on viewport limits, we should redraw the whole viewport
        *view_updated = true;
      } // if

      // The new player position invalidates the fov map, so reset it
      ClearVisMap ();

      // Now we can move the player to the new position
      EntityMove (player, dx, dy);

      // And flag the fov is invalid and needs to be re-calculated
      *fov_changed = true;
    } // else (GetBlockingEntity)
  } // if (!MapIsBlocked)
}