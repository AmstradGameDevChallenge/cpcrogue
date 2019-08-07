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
u8 dirty[MAX_ENTITIES];           // Flags to signal when to draw an entity
TEntity *entities[MAX_ENTITIES];  // List of entities in game
TState state;                     // Current state in game
TEntity *target = NULL;           // Used when searching entities

// Player displacement
i8 dx, dy;
// Enemy displacement
i8 edx[10];
i8 edy = 0;
// Temporary new positions
u8 new_x, new_y;

void main()
{
  u8 ei = 0;
  u8 points[256];
  // Create enemy dx list {1,1,1,1,1,-1,-1,-1,-1,-1}
  for (ei=0; ei!=5; ++ei) {
    edx[ei]=1; edx[9-ei]=-1;
  }

  //ShowLogo();
  cls();

/*
  EntityInit (&player, 3, 3, SPR_PLAYER, PEN_BRIGHT, "Thorbag", TRUE,
    20, 17, 14, 12);
  EntityInit (&enemy, 19, 3, SPR_GOBLIN, PEN_ENTITY, "Goblin", TRUE,
    10, 12, 13, 11);

  entities[0] = &player;
  entities[1] = &enemy;

  dirty[0] = FALSE;
  dirty[1] = FALSE;

  BlackScreen ();
  DisplayLoading ();
  DrawHUD ();
  */
  MapCreate (MAP_WIDTH, MAP_HEIGHT);
  MapDraw ();
  /*
  PrintStats(&player);
  ClearStatus(LOADING_Y, 1);
  InitColors();
  */
/*
  // It's Player's turn
  state = PLAYER_TURN;
  do {
    // Draw all
    EntityDrawEntities(entities, dirty);

    // Get keyboard state
    cpct_scanKeyboard();

    // Get move displacements (if any) according to keys
    dx=0; dy=0;
    action = HandleKeyboard (&dx, &dy);

    new_x = player.x+dx;
    new_y = player.y+dy;
    if (action == PLAYER_MOVE && state == PLAYER_TURN) {
      if (!MapIsBlocked (new_x, new_y)) {
        if (GetBlockingEntity (entities, &target, new_x, new_y) &&
          target != &player) {
          // Attack!
          EntityAttack (&player, target);
        }
        else {
          dirty[0] = TRUE;
          EntityMove (&player, dx, dy);
        }
        cpct_waitHalts(25);
        state = ENEMY_TURN;
      }
    }
    if (state == ENEMY_TURN) {
      cpct_waitHalts(25);
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
          dirty[1] = TRUE;
        }
      }
      else ++ei;
      if (ei > 9) ei = 0;
      // It's Player's turn
      state = PLAYER_TURN;
    }
  }
*/
  while (1);

}
