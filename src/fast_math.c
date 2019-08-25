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
#include "fast_math.h"


u16 manh_distance (u8 x1, u8 y1, u8 x2, u8 y2)
{
  i8 dx, dy;

  dx = x2 - x1;
  dy = y2 - y1;

  dx = abs (dx);
  dy = abs (dy);

  return (dx + dy);
}

u8 rand_range (u8 min, u8 max)
{
  return min + (cpct_rand() * (max-min)) / 255;
}