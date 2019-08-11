#include "cpctelera.h"
#include "room.h"
#include "conio.h"
#include <stdio.h>


void RoomCreate (TRoom *r, u8 x, u8 y, u8 w, u8 h)
{
  r->width = w;
  r->height = h;
  r->left = x;
  r->top = y;
  r->right = x+w+1;
  r->bottom = y+h+1;
}

void GetCenter (TRoom *r, u8 *x, u8 *y)
{
  *x = (r->left + r->right) >> 1;
  *y = (r->top + r->bottom) >> 1;
}
u8 RoomOverlaps (TRoom *r, TRoom *other)
{
/*  locate (1,21);
  printf ("this (%d,%d),(%d,%d)", r->left, r->top, r->right, r->bottom);
  locate (1,22);
  printf ("other (%d,%d),(%d,%d)", other->left, other->top, other->right, other->bottom);*/
  return (r->left <= other->right && r->right >= other->left &&
    r->top <= other->bottom && r->bottom >= other->top);
}