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
//typedef struct TEntity;

struct TContainer
{
  struct TEntity *owner;
  struct TEntity *inventory[MAX_INVENTORY_ITEMS];
  u8 num_items;

  u8 pad[3];  // padding to 8 bytes
};

void init_container (struct TContainer *container);

void append_to_container (
  struct TContainer *container, struct TEntity *entity);

void remove_from_container (
  struct TContainer *container, struct TEntity *entity);