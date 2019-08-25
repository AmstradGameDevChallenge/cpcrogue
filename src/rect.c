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
#include <cpctelera.h>
#include "rect.h"

/*!
  * \brief
  * Creates a new rectangle at position x,y and w,h dimensions
  *
  * \param[in] r
  * Rectangle (ptr) to create
  *
  * \param[in] x,y
  * Top, left coordinate position
  *
  * \param[in] w,h
  *
  * Width and height dimensions
  */
void RectCreate (TRect *r, u8 x, u8 y, u8 w, u8 h)
{
  r->width = w;
  r->height = h;
  r->left = x;
  r->top = y;
  r->right = x+w+1;
  r->bottom = y+h+1;
}

/*!
  * \brief
  * Get the center coordinates of a rectangle
  *
  * \param[in] r
  * Rectangle to process
  *
  * \param[out] x,y
  * Center coordinates
  */
void RectGetCenter (TRect *r, u8 *x, u8 *y)
{
  *x = (r->left + r->right) >> 1;
  *y = (r->top + r->bottom) >> 1;
}

/*!
  * \brief
  * Queries for intersection of two rectangles
  *
  * \param[in] rect, other
  * The two rectangles to query for intersection (overlap)
  *
  * \returns
  * true if the two rectangles overlap
  */
u8 RectIntersect (TRect *rect, TRect *other)
{
  return (rect->left <= other->right && rect->right >= other->left &&
    rect->top <= other->bottom && rect->bottom >= other->top);
}
