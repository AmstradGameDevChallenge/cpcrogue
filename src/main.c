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
#include "components/fighter.h"
#include "components/ai.h"
#include "entity.h"
#include "game_map.h"
#include "input_handler.h"
#include "logo.h"
#include "user_interface.h"
#include "fov.h"
#include "game.h"
#include "fast_math.h"


/****************************************************************************
 *                      MAIN
 ***************************************************************************/
void main()
{
  TAction action;           // Action taken by player
  TState state;             // Current state in game
  u8 left, top;             // Map coords. we want to start drawing
  // Player displacement
  i8 dx, dy;
  TEntity *player=NULL;     // Player entity
  TEntity *e;               // Entity to traverse the entities array
  TAI     *ai;              // AI component of the current entity

  u8 ei = 0;
  u8 fov_changed = false;
  u8 draw_flags;
  u8 log_is_full = false;

  cpct_disableFirmware();

  InitFighterComponents();
  InitEntities();
  NewGame (&player);

  //ShowLogo();

  GetView (player, &left, &top, VIEW_WIDTH, VIEW_HEIGHT);
  // Draw everything
  draw_flags = CLEAR_ALL | STATUS_MSG | CLEAR_STATUS |
    DRAW_HUD | DRAW_MAP | DRAW_STATS;
  UI_Draw (player, left, top, draw_flags);

  // It's duck season!
  state = PLAYER_TURN;

  do {

    // Reset to "no action" performed by player
    action = NONE;

    // Get move displacements (if any) according to keys
    dx=0; dy=0;
    action = HandleKeyboard (&dx, &dy);

    if (action == NEW_LEVEL) {
      //InitEntities();
      //NewGame (&player);
      //ComputeLOS (player->x, player->y, FOV_RADIUS);
      GetView (player, &left, &top, VIEW_WIDTH, VIEW_HEIGHT);
      UI_Draw (player, left, top, draw_flags);
    }

    if (action == PLAYER_MOVE) {
      // Clear the log window if needed when the player moves
      if (log_is_full) {
        ClearStatus (3);
        log_is_full = false;
      } // if (log_is_full)

      EntityMove (player, dx, dy);
      fov_changed = true;
    } // if (action == PLAYER_MOVE)

    e = entities+num_entities;
    while (e != entities) {
      if (e->ai) {
        ai = e->ai;
        ai->TakeTurn(ai);
      }
      --e;
    }

  // Check if we need to recompute field of view
  if (fov_changed)
    ComputeLOS (player->x, player->y, FOV_RADIUS);

  // Draw game and update fov if required
  GameDraw (player, &left, &top, draw_flags, &fov_changed);

  } while (1);
}
