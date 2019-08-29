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
#include "components/fighter.h"
/*
 *
 */
void NewGame (TEntity **player)
{
  // Create the fighter component for the player
  TFighter *player_fighter = FighterCreate(20, 17, 14, 12);

  // Create the player entity with a fighter component
  *player = EntityCreate (0, 0, SPR_PLAYER, PEN_BRIGHT,
    "Thorbag", true, player_fighter);

  MapCreate (MAP_WIDTH, MAP_HEIGHT, *player);

  ComputeLOS ((*player)->x, (*player)->y, FOV_RADIUS);
}

/*
 *
 */
void GameDraw (TEntity *player, u8 *left, u8 *top, u8 draw_flags,
  u8 *fov_changed)
{
  // If player is on viewport limits, we should redraw the whole viewport:
  //  - Compute new field of view
  //  - Get a new viewport
  //  - Draw the whole elements in the game
  if (player->x <= *left || player->y <= *top ||
    player->x > *left+VIEW_WIDTH-1 ||
    player->y > *top+VIEW_HEIGHT-1) {

    ComputeLOS (player->x, player->y, FOV_RADIUS);
    GetView (player, left, top, VIEW_WIDTH, VIEW_HEIGHT);
    UI_Draw (player, *left, *top, draw_flags);
  } // if

  // If only field of view changed, we need to redraw the map
  else if (*fov_changed) {
    MapDraw (*left, *top, VIEW_WIDTH, VIEW_HEIGHT, player);
    *fov_changed = false;
  }

  EntityEraseEntities(*left, *top);
  EntityDrawEntities(*left, *top);
}

