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
#ifndef RECT_H
#define RECT_H

/*!
 * \struct TRect
 * \brief Used to define coordinates and dimensions */
/**@{*/
typedef struct {
  u8 left;    /*!< X position of the rectangle */
  u8 top;     /*!< Y position of the rectangle  */
  u8 right;   /*!< right boundary of the rectangle */
  u8 bottom;  /*!< bottom boundary of the rectangle */
  u8 width;   /*!< width dimension  of the rectangle */
  u8 height;  /*!< height dimension of the rectangle */

} TRect;

/*! Create a new rectangle at specific coords and width, height*/
void RectCreate (TRect *r, u8 x, u8 y, u8 w, u8 h);

/*! Get center of a rectangle */
void RectGetCenter (TRect *r, u8 *x, u8 *y);

/*! true if two rectangles overlap */
u8 RectIntersect (TRect *rect, TRect *other);

#endif