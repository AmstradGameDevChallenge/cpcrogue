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