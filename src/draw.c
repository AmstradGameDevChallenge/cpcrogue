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
#include <stdbool.h>
#include <stdio.h>
#include "consts.h"
#include "draw.h"
#include "entity.h"
#include "components/fighter.h"
#include "components/items.h"
#include "game_map.h"
#include "conio.h"
#include "aux_math.h"
#ifdef DEBUG
  #include <assert.h>
#endif

#ifdef DEBUG
  // forward declaration private fn.
  void draw_axis();
#endif

void draw_game(bool needs_redraw) {

  extern bool stats_changed;
  extern struct TEntity *player;
  struct TEntity *e;

  //cpct_clearScreen_f64(0x0000);
  if (needs_redraw) {
    // Draw map
    draw_map();

    // Draw all entities
    e = entities + num_entities;

    while (--e != entities) {
      if (e->in_world)
        if (distance_sqr (player->x,player->y, e->x, e->y) < FOV_R2)
          entity_draw (e);
    } // while

    // Draw the player
    //entity_erase (player);
    entity_draw (player);

  } // if needs_redraw

  // Draw stats if needed
  if (stats_changed) {
    clr_stats();
    draw_stats();
    stats_changed = false;
  }

}

void draw_map() {
  extern struct TEntity *player;
  i8 x,y;
  i8 start_x, start_y;
  i8 end_x, end_y;

  start_x = player->x < FOV_RADIUS ? 0 : player->x - FOV_RADIUS;
  start_y = player->y < FOV_RADIUS ? 0 : player->y - FOV_RADIUS;
  end_x   = player->x >= MAP_WIDTH-FOV_RADIUS-1 ?
    MAP_WIDTH-1 : player->x+FOV_RADIUS;
  end_y   = player->y >= MAP_HEIGHT-FOV_RADIUS-1 ?
    MAP_HEIGHT-1 : player->y+FOV_RADIUS;

  for (y=start_y; y <= end_y; ++y)
  for (x=start_x; x <=end_x; ++x) {
    if ( !(player->x == x && player->y == y) )
      draw_tile (x, y, PEN_BRIGHT, PEN_CLEAR);
  }
}

void draw_tile (i8 x, i8 y, u8 fg_color, u8 bg_color) {

  struct TTile *current_tile = &game_map.tiles[y][x];

#ifdef DEBUG
  assert (x >= 0 && y >= 0 && x < MAP_WIDTH && y < MAP_HEIGHT);
#endif

  if (current_tile->t_flags & BLOCKED) {
    // Draw wall
    putchar_f ((void*)VMEM_MAP, x,y, SPR_WALL, fg_color, bg_color);
  } // if (blocked)

  else {
    // Draw floor
    putchar_f ((void*)VMEM_MAP, x,y, SPR_FLOOR, fg_color, bg_color);
  }
}

void draw_stats() {
  extern u8 msg[];
  extern struct TEntity *player;

  sprintf (msg, "Level %d/%d",
    player->xp_level, player->fighter->xp);
  cpct_drawStringM1_f (msg, (void*)(VMEM_STATS_XP),
    PEN_BRIGHT, PEN_CLEAR);

  sprintf (msg, "HP: %d/%d",
    player->fighter->hp, player->fighter->max_hp);
  cpct_drawStringM1_f (msg, (void*)(VMEM_STATS_HP),
    PEN_BRIGHT, PEN_CLEAR);

  sprintf (msg, "Gold: %d",
    player->item->value);
  cpct_drawStringM1_f (msg, (void*)(VMEM_STATS_GOLD),
    PEN_BRIGHT, PEN_CLEAR);
}


#ifdef DEBUG
void draw_vismap () {
  u8 x,y;

  cpct_clearScreen_f64(0x0000);
  draw_axis();

  y = MAP_HEIGHT;
  do {
    --y;
    x = MAP_WIDTH;
    do {
      --x;
      if (is_visible (x,y))
        putchar_f ((void*)VMEM_MAP, x, y, '.', PEN_BRIGHT, PEN_CLEAR);
      else
        putchar_f ((void*)VMEM_MAP, x, y, '#', PEN_BRIGHT, PEN_CLEAR);
    } while (x);
  } while (y);
}

void draw_axis() {
  u8 y = MAP_HEIGHT;

  cpct_drawStringM1_f(" 01234567890123456789012345678901",
    VMEM, PEN_BRIGHT, PEN_CLEAR);

  do {
    putchar_f (VMEM, 0,y, y+64, PEN_BRIGHT, PEN_CLEAR);
    --y;
  } while (y);
}
#endif