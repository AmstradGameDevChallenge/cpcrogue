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
#ifndef CONST_H
#define CONST_H

#include <stdbool.h>

#ifndef NULL
#define NULL 0
#endif

///< Max allowed entities in game
#define MAX_ENTITIES 32

///< How many fighter components we allocate, by default we allocate as many
/// as max entities
#define MAX_FIGHTER_COMPONENTS  MAX_ENTITIES

///< How many AI components we allocate, by default we allocate as many
/// as max entities
#define MAX_AI_COMPONENTS  MAX_ENTITIES

// Map dimensions
#define MAP_WIDTH       28
#define MAP_HEIGHT      18

// Pen Colors
#define   PEN_ENTITY      3
#define   PEN_CLEAR       0
#define   PEN_TILE        3
#define   PEN_EXPLORED    1
#define   PEN_BRIGHT      2
#define   PEN_NORMAL      3
#define   PEN_MESSAGES    1
#define   PEN_GOLD        1
#define   PEN_POTION      2

// Game Sprites
#define   SPR_WALL    207
#define   SPR_FLOOR   144
#define   SPR_PLAYER  '@'
#define   SPR_GOBLIN  'g'
#define   SPR_ORC     'o'
#define   SPR_BAT     'B'
#define   SPR_REMAINS '%'
#define   SPR_GOLD    '$'
#define   SPR_POTION  175 // ¡

// Where the visible areas start, these offsets are added to
// everything we draw so they appear in the correct playable coordinates
#define VIEW_X            1     // X map area display
#define VIEW_Y            1     // Y map area display
#define LOG_W             38*2  // in bytes
#define LOG_X             1     // X log messages area
#define LOG_Y             20    // Y log messages area
#define STATS_Y           5
#define STATS_W           80-MAP_WIDTH*2-4

// Cell Flags
#define   BLOCKED         0x01  ///< Blocks movement
#define   BLOCKS_LIGHT    0x02  ///< Light does not pass through this cell
#define   EXPLORED        0x04  ///< Has been explored by player
#define   HAS_ENTITY      0x08  ///< There's an entity in the cell
#define   HAS_DEAD_ENTITY 0x10  ///< There's an entity in the cell

// Inventory and items
#define   MAX_INVENTORY_ITEMS 16  ///< Inventory capacity

// Experience and level-ups
#define   LEVEL_UP_BASE   10//100
#define   LEVEL_UP_FACTOR 15// 75

// LOS constants
#define   FOV_RADIUS    4     // Max distance player can see
#define   FOV_R2    FOV_RADIUS*FOV_RADIUS // Max distance player can see

//!< Start of Amstrad CPC video memory
#define VMEM (0xC000)
//!< Start of the game map drawing area in the Amstrad CPC video memory
#define VMEM_MAP (0xC000+VIEW_Y*0x50+VIEW_X*2)
//!< Start of the message log display area in the Amstrad CPC video memory
#define VMEM_LOG (0xC000+ LOG_Y*0x50+LOG_X*2)
//!< Start of the stats drawing area in the Amstrad CPC video memory
#define VMEM_STATS_XP (0xC000+STATS_Y*0x50+(MAP_WIDTH+VIEW_X+1)*2)
#define VMEM_STATS_HP (0xC000+(STATS_Y+1)*0x50+(MAP_WIDTH+VIEW_X+1)*2)
#define VMEM_STATS_GOLD (0xC000+(STATS_Y+2)*0x50+(MAP_WIDTH+VIEW_X+1)*2)


// Available actions for player
typedef enum TAction {
  NONE, PLAYER_MOVE, PLAYER_WAIT, NEW_LEVEL
} TAction;


#endif