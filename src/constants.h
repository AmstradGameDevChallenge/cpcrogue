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
#ifndef CONST_H
#define CONST_H


/*!
 * \brief Firmware colors used in the game
 */
#define INK_BLACK         20
#define INK_DARK_BLUE     04
#define INK_PASTEL_YELLOW 03
#define INK_ORANGE        14
#define INK_PINK          07

/****************************************************************************
 * Special ASCII codes
 ***************************************************************************/
/*#define US  0x1f        // LOCATE
#define FS  0x1c        // INK
#define GS  0x1d        // BORDER
#define SO  0x0e        // PAPER
#define SI  0x0f        // PEN
#define FF  0x0c        // CLS
*/


// Max allowed entities in game
#define MAX_ENTITIES 32

// Max mobs in a room
#define MAX_MOBS_IN_ROOM  3

// Map dimensions
#define MAP_WIDTH       64
#define MAP_HEIGHT      32
#define MIN_ROOM_SIZE   4
#define MAX_ROOM_SIZE   8
#define MIN_ROOMS       10
#define MAX_ROOMS       25

// Grid
#define SPOTS_IN_GRID   10
#define GRID_WIDTH      5
#define GRID_HEIGHT     3
#define ROOM_NONE       GRID_WIDTH * GRID_HEIGHT

// Where the visible map starts, these offsets are added to
// everything we draw so they appear in the correct playable coordinates
// Viewport dimensions
#define VIEW_WIDTH      28
#define VIEW_HEIGHT     18
#define VIEW_X          1
#define VIEW_Y          1
#define STATS_X         (VIEW_X + VIEW_WIDTH +1)
#define STATS_Y         2
#define STATUS_X        1
#define STATUS_W        38*2 // in bytes
#define STATUS_Y        20
#define LOADING_X       STATUS_X
#define LOADING_Y       STATUS_Y

// Game Sprites
#define   SPR_WALL    207
#define   SPR_FLOOR   144
#define   SPR_PLAYER  '@'
#define   SPR_GOBLIN  'g'
#define   SPR_ORC     'o'

// Sprite Colors
/*#define   INK_BG          0
#define   INK_DARK        1
#define   INK_BRIGHT      25
#define   INK_NORMAL      16
*/
#define   PEN_ENTITY      3
#define   PEN_CLEAR       0
#define   PEN_TILE        3
#define   PEN_EXPLORED    1
#define   PEN_BRIGHT      2
#define   PEN_NORMAL      3
#define   PEN_MESSAGES    1

// Cell Flags
#define   BLOCKED       0x01  ///< Blocks movement
#define   BLOCKS_LIGHT  0x02  ///< Light does not pass through this cell
#define   EXPLORED      0x04  ///< Has been explored by player
#define   HAS_ENTITY    0x08  ///< There's an entity in the cell

// Flags for drawing UI
#define   CLEAR_ALL     0x01  ///< Clear whole screen before drawing anything
#define   DRAW_MAP      0x02  ///< Draw map viewport
#define   CLEAR_STATUS  0x04  ///< Clear status after finishing drawing
#define   DRAW_STATS    0x08  ///< Draw stats section
#define   STATUS_MSG    0x10  ///< Display a status message
#define   DRAW_HUD      0x20  ///< Draw HUD decoration

// LOS constants
#define   FOV_RADIUS    5     // Max distance player can see

// Available actions for player
typedef enum TAction {
  NONE, PLAYER_MOVE, NEW_LEVEL
} TAction;

// Possible states in game
typedef enum TState {
  PLAYER_TURN, ENEMY_TURN
} TState;

//!< Start of Amstrad CPC video memory
#define VMEM (void*)0xC000

//!< Start of the game map drawing area in the Amstrad CPC video memory
#define VMEM_MAP (void*)(0xC000+VIEW_Y*0x50+VIEW_X*2)

//!< Start of the stats display area in the Amstrad CPC video memory
#define VMEM_STATS (void*)(0xC000+STATS_Y*0x50+STATS_X*2)

//!< Start of the message log display area in the Amstrad CPC video memory
#define VMEM_STATUS (0xC000+ STATUS_Y*0x50+STATUS_X*2)

//!< Bytes/line
#define ONELINE 80
#endif