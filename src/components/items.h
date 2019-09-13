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
typedef struct TEntity;
typedef struct TContainer;

struct TItem
{
  struct TEntity    *owner;
  struct TContainer *container;
  bool              is_gold;
  u16               gold_ammount;

  u8 padding;       // pad to 8 bytes
};

void init_item(struct TItem *item, struct TEntity *owner, bool is_gold);
void pick_up (struct TItem *item, struct TEntity *entity);
void drop (struct TItem *item, i8 x, i8 y);
void take_gold(struct TItem *item_gold);