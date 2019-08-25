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
#ifndef FAST_MATH_H
#define FAST_MATH_H

#include <cpctelera.h>


inline u8 clamp (u8 value, u8 min, u8 max)
{
  return (value > max) ? max :
    (value < min) ? min : value;
}
inline u8 min (u8 a, u8 b)
{
  return (a < b) ? a : b;
}
inline u8 max (u8 a, u8 b)
{
  return (a > b) ? a : b;
}

inline u8 abs (i8 value)
{
  return value < 0 ? -value : value;
}
inline i8 sign (i8 value)
{
  return value < 0 ? -1 : 1;
}

u8 rand_range (u8 min, u8 max);

u16 manh_distance (u8 x1, u8 y1, u8 x2, u8 y2);

inline u16 distance_sqr (u8 x1, u8 y1, u8 x2, u8 y2) {
  return ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}


#endif