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
#include "constants.h"
#include "conio.h"
#include "entity.h"
#include "game_map.h"
#include "input_handler.h"
#include "logo.h"
#include "user_interface.h"
#include "fov.h"
#include "fast_math.h"

/****************************************************************************
 *                      Initialize Colors
 ***************************************************************************/
void InitColors()
{
  ink (0, INK_BG,INK_BG);
  ink (1, INK_DARK, INK_DARK);
  ink (2, INK_BRIGHT, INK_BRIGHT);
  ink (3, INK_NORMAL, INK_NORMAL);

  border (0); paper (0);
}
/****************************************************************************
 *                      MAIN
 ***************************************************************************/
TAction action = NONE;            // Action taken by player
TEntity player, enemy;            // Entities to be placed
TEntity *entities[MAX_ENTITIES];  // List of entities in game
TState state;                     // Current state in game
TEntity *target = NULL;           // Used when searching entities
u8 left, top;                     // Map coords. we want to start drawing

// Player displacement
i8 dx, dy;
// Enemy displacement
const i8 edx[10] = {1,1,1,1,1,-1,-1,-1,-1,-1};
i8 edy = 0;
// Temporary new positions
u8 new_x, new_y;

void main()
{
  u8 ei = 0;
  u8 view_updated = FALSE;
  u8 fov_changed = FALSE;

  //ShowLogo();
  cls();

  EntityInit (&player, 0, 0, SPR_PLAYER, PEN_BRIGHT, "Thorbag", TRUE,
    20, 17, 14, 12);
  EntityInit (&enemy, 19, 3, SPR_GOBLIN, PEN_ENTITY, "Goblin", TRUE,
    10, 12, 13, 11);

  entities[0] = &player;
  entities[1] = &enemy;

  BlackScreen ();
  DisplayLoading ();
  DrawHUD ();

  MapCreate (MAP_WIDTH, MAP_HEIGHT, &player);
  GetView (&player, &left, &top, VIEW_WIDTH, VIEW_HEIGHT);
  ComputeLOS (player.x, player.y, FOV_RADIUS);
  MapDraw (left, top, VIEW_WIDTH, VIEW_HEIGHT, &player);
  PrintStats(&player);
  ClearStatus(LOADING_Y, 1);
  InitColors();

  // It's Player's turn
  state = PLAYER_TURN;

  do {
    // Check if we need to recompute field of view
    if (fov_changed) {
      ComputeLOS (player.x, player.y, FOV_RADIUS);
      MapDraw (left, top, VIEW_WIDTH, VIEW_HEIGHT, &player);
      fov_changed = FALSE;
    }
    // Draw all
    // Check if we should update viewport
    if (player.x < left || player.y <top ||
      player.x > left+VIEW_WIDTH || player.y > top+VIEW_HEIGHT) {
      view_updated = TRUE;
    }
    if (view_updated) {
      view_updated = FALSE;
      BlackScreen ();
      cls();
      DisplayLoading ();
      MapDraw (left, top, VIEW_WIDTH, VIEW_HEIGHT, &player);
      ClearStatus(LOADING_Y, 1);
      DrawHUD ();
      PrintStats(&player);
      InitColors();
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
      BlackScreen ();
      cls();
      DisplayLoading ();
      MapCreate (MAP_WIDTH, MAP_HEIGHT, &player);
      ComputeLOS(player.x, player.y, FOV_RADIUS);
      GetView (&player, &left, &top, VIEW_WIDTH, VIEW_HEIGHT);
      MapDraw (left, top, VIEW_WIDTH, VIEW_HEIGHT, &player);
      ClearStatus(LOADING_Y, 1);
      DrawHUD ();
      PrintStats(&player);
      InitColors ();
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
          MapSetNotVisible (player.x, player.y, FOV_RADIUS);
          EntityMove (&player, dx, dy);
          fov_changed = TRUE;
        }
        //cpct_waitHalts(15);
        state = ENEMY_TURN;
      }
    }
    if (state == ENEMY_TURN) {
      //cpct_waitHalts(15);
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
          EntityMove (&enemy, edx[ei++], edy);
        }
      }
      else ++ei;
      if (ei > 9) ei = 0;
      // It's Player's turn
      state = PLAYER_TURN;
    }
  } while (1);
}
