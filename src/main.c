//-------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2018 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
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
//-----------------------------------------------------------------------------

/**********************************
 *  CPC ROGUE
 *  Jul 2019 by Andres Mata
 **********************************/
#include <cpctelera.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "constants.h"
#include "conio.h"
#include "entity.h"
#include "game_map.h"
#include "input_handler.h"
#include "logo.h"
#include "user_interface.h"
#include "fov.h"
#include "game.h"
#include "fast_math.h"


// Enemy displacement
const i8 edx[10] = {1,1,1,1,1,-1,-1,-1,-1,-1};

/****************************************************************************
 *                      MAIN
 ***************************************************************************/
void main()
{
  TAction action;           // Action taken by player
  TState state;             // Current state in game
  TEntity *target;          // Used when searching entities
  u8 left, top;             // Map coords. we want to start drawing
// Temporary new positions
  u8 new_x, new_y;
  // Player displacement
  i8 dx, dy;
  TEntity player, enemy;            // Entities to be placed
  u8 ei = 0;
  u8 view_updated = false;
  u8 fov_changed = false;
  u8 draw_flags;

  NewGame (&player, &enemy);
  ComputeLOS (player.x, player.y, FOV_RADIUS);

  //ShowLogo();
  GetView (&player, &left, &top, VIEW_WIDTH, VIEW_HEIGHT);

  // Draw everything
  draw_flags = CLEAR_ALL | STATUS_MSG | CLEAR_STATUS |
    DRAW_HUD | DRAW_MAP | DRAW_STATS;
  DrawGame (&player, left, top, draw_flags);

  // It's Player's turn
  state = PLAYER_TURN;

  do {
    // Check if we need to recompute field of view
    if (fov_changed) {
      ComputeLOS (player.x, player.y, FOV_RADIUS);
      MapDraw (left, top, VIEW_WIDTH, VIEW_HEIGHT, &player);
      fov_changed = false;
    }
    // Draw all
    // Check if we should update viewport
    if (player.x <= left || player.y <=top ||
      player.x > left+VIEW_WIDTH-1 || player.y > top+VIEW_HEIGHT-1) {
      view_updated = true;
    }
    if (view_updated) {
      view_updated = false;
      ComputeLOS (player.x, player.y, FOV_RADIUS);
      GetView (&player, &left, &top, VIEW_WIDTH, VIEW_HEIGHT);
      DrawGame (&player, left, top, draw_flags);
    }
    EntityDrawEntities(entities, left, top);

    // Get keyboard state
    cpct_scanKeyboard();

    // Get move displacements (if any) according to keys
    dx=0; dy=0;
    action = HandleKeyboard (&dx, &dy);

    new_x = player.x+dx;
    new_y = player.y+dy;

    if (action == NEW_LEVEL) {
      MapCreate (MAP_WIDTH, MAP_HEIGHT, &player);
      ComputeLOS(player.x, player.y, FOV_RADIUS);
      GetView (&player, &left, &top, VIEW_WIDTH, VIEW_HEIGHT);

      DrawGame (&player, left, top, draw_flags);
    }
    if (action == PLAYER_MOVE && state == PLAYER_TURN) {
      if (!MapIsBlocked (new_x, new_y)) {
        if (GetBlockingEntity (entities, &target, new_x, new_y) &&
          target != &player) {
          // Attack!
          EntityAttack (&player, target);
        }
        else {
          // Reset tile visibility around player's FOV
          ClearVisMap ();
          EntityMove (&player, dx, dy);
          fov_changed = true;
        }
        state = ENEMY_TURN;
      }
    }
    if (state == ENEMY_TURN) {
      // Enemy actions
      new_x = enemy.x + edx[ei];
      new_y = enemy.y;
      if (!MapIsBlocked (new_x, new_y)) {
        if (GetBlockingEntity (entities, &target, new_x, new_y) &&
          target != &enemy) {
          EntityAttack (&enemy, target);
          PrintStats(&player);
        }
        else {
          EntityMove (&enemy, edx[ei++], 0);
        }
      }
      else ++ei;
      if (ei > 9) ei = 0;
      // It's Player's turn
      state = PLAYER_TURN;
    }
  } while (1);
}
