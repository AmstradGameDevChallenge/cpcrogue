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
inline u8 abs (i8 value)
{
  return value < 0 ? -value : value;
}

inline i8 sign (i8 value)
{
  return value < 0 ? -1 : 1;
}

inline u16 distance_sqr (i8 x1, i8 y1, i8 x2, i8 y2) {
  return ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
