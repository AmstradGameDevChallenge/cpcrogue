#ifndef RECT_H
#define RECT_H
#include "cpctelera.h"

typedef struct {
  u8 left, right, top, bottom;    // Rect coordinates
  u8 width, height;               // Dimensions
} TRect;

void RectCreate (TRect *r, u8 x, u8 y, u8 w, u8 h);
void RectGetCenter (TRect *r, u8 *x, u8 *y);
u8 RectIntersect (TRect *rect, TRect *other);

#endif