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

/*!
 * \defgroup game_map
 *
 * \brief Map creation and query routines
 *
 * The structures and functions in this module helps with the creation and
 * query of the map in the game.
 *
 * The game stores information of each tile in the map. Each tile needs to
 * keep track of certain attributes like is it walkable?, or blocks light?
 * etc.
 *
 */
/**@{*/
//#include "consts.h"

/*!
 * \struct  TTile
 *
 * \brief Single tile information
 */
struct TTile {
  u8 t_flags; ///< flag attributes for a specific tile
};

/*!
 * \struct TMap
 *
 * \brief Map dimensions and tiles it contains
 *
 */
struct TMap{
  u8 width;   ///< Game map width
  u8 height;  ///< Game map height
  struct TTile tiles[MAP_HEIGHT][MAP_WIDTH]; ///<every single tile in the map
};

/*!
 * \brief Global variable to access the game map
 */
extern struct TMap game_map;


/*!
 * \brief Create a new map
 */
void map_create (u8 width, u8 height);

/*!
 * \brief True if specified map coordinates block movement (i.e: wall)
 *
 * \param[in] x,y Map coordinates to query.
 *
 * \returns true if tile blocks movement.
 */
inline bool tile_blocks_movement (i8 x, i8 y)
{
  return game_map.tiles[y][x].t_flags & BLOCKED;
}

/*!
 * \brief True if specified map coordinates block movement (i.e: wall)
 *
 * \param[in] x,y Map coordinates to query.
 *
 * \returns true if tile blocks light.
 */
inline bool tile_blocks_light (i8 x, i8 y)
{
  return game_map.tiles[y][x].t_flags & BLOCKS_LIGHT;
}