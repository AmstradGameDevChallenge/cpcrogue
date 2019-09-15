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
typedef struct TFighter;
typedef struct TAI;
typedef struct TContainer;
typedef struct TItem;

struct TEntity {
  i8 x, y;        ///< Current position
  i8 px, py;      ///< Previous position
  u8 spr;         ///< ASCII char to draw this entity
  u8 color;       ///< Color to draw this entity
  u8 name[15];    ///< Name to display in messages
  bool in_world;  ///< true if it's in the world
  u8 xp_level;    ///< Experience level

  struct TFighter   *fighter;   ///< A fighter component for combat
  struct TAI        *ai;        ///< An AI component if intelligent
  struct TContainer *container; ///< Container if carries items
  struct TItem      *item;      ///< Item if pickable
};

extern struct TEntity entities[];
extern u8 num_entities;


void init_entities();
struct TEntity *entity_create (i8 x, i8 y, u8 spr, u8 color, u8 name[],
  struct TFighter   *fighter,
  struct TAI        *ai,
  struct TContainer *container,
  struct TItem      *item,
  bool              is_gold);
//void entity_erase (struct TEntity *e);
void entity_draw  (struct TEntity *e);
void entity_move (struct TEntity *e, i8 dx, i8 dy);
struct TEntity *get_fighter_at (i8 x, i8 y);
struct TEntity *get_item_at (i8 x, i8 y);
void add_to_world (struct TEntity *e, i8 x, i8 y);
void remove_from_world (struct TEntity *e);
void check_level();