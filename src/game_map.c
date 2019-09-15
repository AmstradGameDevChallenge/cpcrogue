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
#include "consts.h"
#include "game_map.h"


extern struct TEntity entities[];
extern u8 num_entities;

// forward declaration of private functions
void init_tiles (u8 width, u8 height);

/*!
 * The global variable **game_map** holds information about the tiles in the
 * current generated map. It's a global variable and can be accessed from
 * any file to query information about a specific tile or dimensions of the
 * map.
 */
struct TMap game_map;


/*!
 * Creates a very basic dungeon
 *
 * \param[in] width Width of the map
 * \param[in] height Height of the map
 */
void map_create (u8 width, u8 height) {
  init_tiles(width, height);
}
//===========================================================================
//===========================================================================
/***
 *       ___  ____ _ _  _ ____ ___ ____
 *       |__] |__/ | |  | |__|  |  |___
 *       |    |  \ |  \/  |  |  |  |___
 *    ____ _  _ _  _ ____ ___ _ ____ _  _ ____
 *    |___ |  | |\ | |     |  | |  | |\ | [__
 *    |    |__| | \| |___  |  | |__| | \| ___]
 *
 */
//===========================================================================
//===========================================================================

/*! \brief
 * Initializes the map to a given width and height.
 *
 * All the tiles in the map  are set to block movement and light. Also
 * initializes the visibility map to all cells not visible.
 *
 * \param width   Width of the map to initialize
 * \param height  Height of the map to initialize
 */
 void init_tiles (u8 width, u8 height) {

  u8 x, y;

  game_map.width  = width;
  game_map.height = height;

  // All tiles by default allow movement (walls) and light
  cpct_memset (game_map.tiles, 0, sizeof (game_map.tiles));

  game_map.tiles[10][12].t_flags            |= BLOCKED | BLOCKS_LIGHT;
  game_map.tiles[14][5].t_flags             |= BLOCKED | BLOCKS_LIGHT;

  for (x=0; x<MAP_WIDTH; ++x) {
    game_map.tiles[0][x].t_flags            |= BLOCKED | BLOCKS_LIGHT;
    game_map.tiles[MAP_HEIGHT-1][x].t_flags |= BLOCKED | BLOCKS_LIGHT;
  }

  for (y=0; y<MAP_HEIGHT; ++y) {
    game_map.tiles[y][0].t_flags            |= BLOCKED | BLOCKS_LIGHT;
    game_map.tiles[y][MAP_WIDTH-1].t_flags  |= BLOCKED | BLOCKS_LIGHT;
  }

  // Initialize the visibility map
  //init_vismap();
 }