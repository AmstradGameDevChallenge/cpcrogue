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
#include "consts.h"
#include "input.h"
#include "draw.h"
#include "entity.h"
#include "components/ai.h"
#include "components/fighter.h"
#include "components/container.h"
#include "components/items.h"
#include "game_map.h"
#include "conio.h"
#include "potions.h"


// globals
bool fov_changed, stats_changed;
struct TEntity *player;
struct TContainer inv_player;
struct TItem item_g, item_orc, pgold, igold, igold2, ipotion;
u8 msg[38];


//---------------------------------------------------------------------------
void game_loop() {

  i8 dx, dy;
  struct TEntity *e;
  struct TAI *ai;
  TAction player_action = NONE;

  while (1) {

    // Handle player input
    dx = dy = 0;
    fov_changed = false;
    player_action = handle_keys(&dx, &dy);

    if (player_action != NONE) clr_log();
    if (player_action == PLAYER_MOVE) {
      entity_move (player, dx, dy);
    } // if (action == PLAYER_MOVE)

    // Calculate fov (only if needed)
    //compute_fov();

    if (player_action != NONE) {
      e = entities + num_entities;
      while(--e != entities) {
        if (e->ai) {
          ai = e->ai;
          ai->take_turn(ai);
        } // if (e->ai)
      } // while (e != entities)
    } // if (player_action != NONE)

    // Draw the game
    draw_game(fov_changed);
  } // while (1)
} // game_loop

//---------------------------------------------------------------------------
void game_init() {
  struct TEntity *e, *e2, *e3, *egold, *egold2, *heal_potion;
  struct TFighter *mob_f1, *mob_f2, *mob_f3, *pl_fig;
  struct TAI *mob_ai, *mob_ai2, *mob_ai3;

  init_entities();
  init_ai();
  init_fighters();

  map_create (MAP_WIDTH, MAP_HEIGHT);

  // Create the player entity with a fighter component
  pl_fig = fighter_create(10, 0, NULL);
  player = entity_create(11, 10, SPR_PLAYER, PEN_BRIGHT,
    "Thorbag", pl_fig, NULL, &inv_player, &pgold, false);
  player->in_world = false;
  player->xp_level = 1;

  mob_ai = basic_ai_create ();
  mob_f1 = fighter_create(8, 25, kill_mob);
  e = entity_create(5, 3, SPR_GOBLIN, PEN_NORMAL,
    "Goblin", mob_f1, mob_ai, NULL, &item_g, false);

  mob_ai2 = basic_ai_create ();
  mob_f2 = fighter_create(12, 50, kill_mob);
  e2 = entity_create(8, 6, SPR_ORC, PEN_BRIGHT,
    "Orc", mob_f2, mob_ai2, NULL, &item_orc, false);

  mob_ai3 = basic_ai_create ();;
  mob_f3 = fighter_create(7, 20, kill_mob);
  e3 = entity_create(13, 8, SPR_BAT, PEN_NORMAL,
    "Bat", mob_f3, mob_ai3, NULL, NULL, false);

// Gold
  egold = entity_create(15,8, SPR_GOLD, PEN_GOLD,
    "gold", NULL, NULL, NULL, &igold, true);
  egold2 = entity_create(19,10, SPR_GOLD, 1,
    "gold", NULL, NULL, NULL, &igold2, true);

// Heal potion
  heal_potion = entity_create (25, 9, SPR_POTION, PEN_POTION,
    "Heal Potion", NULL, NULL, NULL, &ipotion, false);
  ipotion.value = 5;
  ipotion.use_fn = cast_heal;

  fov_changed = false;
  stats_changed = true;

  // first time need to draw the game manually
  draw_game(true);
}

/*             _______________________________________________
 *    ________|    _     _               __        __   ___   |_______
 *    \       |   / '   / \   |\    /|  |__  |    |  |   |    |      /
 *     \      |   \_.  | - |  |  \/  |  |__  |__  |__|   |    |     /
 *     /      |_______________________________________________|     \
 *    /__________)                                        (__________\
 */
void main(void) {
  game_init();
  game_loop();
}
