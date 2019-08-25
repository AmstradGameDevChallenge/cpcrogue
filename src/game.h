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
#ifndef GAME_H
#define GAME_H

void
NewGame (TEntity **player);

void
GameDraw (TEntity *player,
  u8 *fov_changed, u8 *view_updated, u8 *left, u8 *top, u8 draw_flags);

void
GameDoPlayerTurn (TEntity *player, u8 dx, u8 dy, u8 left, u8 top,
  u8 *log_is_full, u8 *view_updated, u8 *fov_changed);

#endif