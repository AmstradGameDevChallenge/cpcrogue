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
#include <assert.h>
#include "constants.h"
#include "fast_math.h"
#include "conio.h"
#include "game_map.h"
#include "fov.h"

/*! \brief Visibility map, implemented as a bitarray */
u8 vis_map[MAP_HEIGHT][MAP_WIDTH/8];

/*
 * Reset the visibility map to all *not visible*. In current implementation
 * what it does is zeroes all bytes in the \ref vis_map array.
 */
void ClearVisMap ()
{
  cpct_memset (vis_map, 0, sizeof (vis_map));
}

/*!
 * \param x,y Visibility map coordinates to set as visible
 */
void SetVisible (u8 x, u8 y)
{
  u8 *dest;

  assert (x < MAP_WIDTH && x < 128);
  assert (y < MAP_HEIGHT && y < 128);
  dest = &vis_map[y][x>>3];
  *dest |= 0x80 >> (x&7);
}

/*!
 * \param x,y Visibility map coordinates to set as visible
 *
 * \return 1 if the tile is visible, 0 otherwise
 */
u8 isVisible (u8 x, u8 y)
{
  u8 vis_byte;
  u8 query_mask;

  assert (x < MAP_WIDTH && x < 128);
  assert (y < MAP_HEIGHT && y < 128);
  vis_byte = vis_map[y][x>>3];
  query_mask = 0x80 >> (x&7);

  return vis_byte & query_mask;
}

/*!
 * Computes Light of Sight from a specific point using basic *ray-casting*.
 * Imaginary “rays” are casted away from the specified position and sent in
 * every direction. If they cross a new tile, it is displayed. If this tile
 * is an obstacle, the rays stop here. Otherwise, it goes through the next
 * tile, and so on.
 *
 * \param origin_x, origin_y Starting point, usually player position
 * \param range Max distance to compute, usually player's field of view
 */
void ComputeLOS (u8 origin_x, u8 origin_y, u8 range)
{
  TRect area;
  u8 range_sqr = range*range;

  // Start point is visible by definition
  SetVisible (origin_x, origin_y);

  // Create a Rect around the origin
  RectCreate (&area, origin_x - range, origin_y - range,
    range*2+1, range*2+1);

  if (area.top > 127) area.top = 0;
  if (area.left > 127) area.left = 0;
  if (area.bottom > MAP_HEIGHT-1) area.bottom = MAP_HEIGHT-1;
  if (area.right > MAP_WIDTH-1) area.right = MAP_WIDTH-1;

  // Cast rays towards the top and bottom of the area
  for (u8 x=area.left; x<area.right; ++x) {
    assert (x < MAP_WIDTH && x < 128);
    TraceLine (origin_x, origin_y, x, area.top, range_sqr);
    TraceLine (origin_x, origin_y, x, area.bottom-1, range_sqr);
  }

  for (u8 y=area.top+1; y<area.bottom-1; ++y) {
    assert (y < MAP_HEIGHT && y < 128);
    TraceLine (origin_x, origin_y, area.left, y, range_sqr);
    TraceLine (origin_x, origin_y, area.right-1, y, range_sqr);
  }
}

/*!
 * Traces a line between two game map points using *Bresenham's* line
 * algorithm. For each tile the line *touches* the FOV information is
 * updated. The line is constrained to *range* distance or the first wall
 * it encounters.
 *
 * \param x1,y1 Origin point coordinates
 * \param x2,y2 Destination point coordinates
 * \param range Max line Distance (usually FOV radius)
 */
void TraceLine (u8 x1, u8 y1, u8 x2, u8 y2, u8 range)
{
  u8 dx, dy;
  i8 sx, sy;
  i8 error, error2;
  u8 origin_x, origin_y;

  origin_x = x1;
  origin_y = y1;

  dx = x2-x1;
  dy = y2-y1;
  sx = sign (dx);
  sy = sign (dy);
  dx = abs (dx);
  dy = abs (dy);
  error = dx-dy;


  while(1) {
    //*ptr++ = x1;
    //*ptr++ = y1;
    //locate (x1,y1);putchar('#');

    // Exit when we reach target point or we are beyond range distance
    if (x1==x2 && y1==y2) break;

    error2 = error << 1;
    if (error2 > -dx) {
      error -= dy;
      x1 += sx;
    }
    if (error2 < (i8)dx) {
      error += dx;
      y1 += sy;
    }
    //if (manh_distance (origin_x,origin_y, x1,y1) > range)
    if (distance_sqr (origin_x,origin_y, x1,y1) > range)
      break;

    // Set visible every cell we 'touch' along the line
    SetVisible (x1,y1);
    // Exit if we found something that blocks light (i.e:wall)
    if (MapBlocksLight (x1, y1)) break;
  }
}