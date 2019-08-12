#include "rect.h"

void RectCreate (TRect *r, u8 x, u8 y, u8 w, u8 h)
{
  r->width = w;
  r->height = h;
  r->left = x;
  r->top = y;
  r->right = x+w+1;
  r->bottom = y+h+1;
}

void RectGetCenter (TRect *r, u8 *x, u8 *y)
{
  *x = (r->left + r->right) >> 1;
  *y = (r->top + r->bottom) >> 1;
}

u8 RectIntersect (TRect *rect, TRect *other)
{
  return (rect->left <= other->right && rect->right >= other->left &&
    rect->top <= other->bottom && rect->bottom >= other->top);
}
