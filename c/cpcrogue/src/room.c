#include "cpctelera.h"
#include "room.h"
#include "conio.h"
#include <stdio.h>


void _RoomCreate (Room *r, u8 x, u8 y, u8 w, u8 h)
{
  r->x1 = x;
  r->y1 = y;
  r->x2 = x+w;
  r->y2 = y+h;
}

void _GetCenter (Room *r, u8 *x, u8 *y)
{
  *x = (r->x1 + r->x2) >> 1;
  *y = (r->y1 + r->y2) >> 1;
}
u8 _RoomOverlaps (Room *r, Room *other)
{
/*  locate (1,21);
  printf ("this (%d,%d),(%d,%d)", r->x1, r->y1, r->x2, r->y2);
  locate (1,22);
  printf ("other (%d,%d),(%d,%d)", other->x1, other->y1, other->x2, other->y2);*/
  return (r->x1 <= other->x2 && r->x2 >= other->x1 &&
    r->y1 <= other->y2 && r->y2 >= other->y1);
}