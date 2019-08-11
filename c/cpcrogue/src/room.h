#ifndef ROOMS_H
#define ROOMS_H

typedef struct {
  u8 left, right, top, bottom;    // Rect coordinates
  //u8 center_x, center_y;
  u8 width, height;               // width,height including walls
  u8 grid_id;                     // Grid id where the room is placed
} TRoom;

void RoomCreate (TRoom *r, u8 x, u8 y, u8 w, u8 h);
void PlaceRoom (TRoom *r);
u8 RoomOverlaps (TRoom *r, TRoom *other);
void GetCenter (TRoom *r, u8 *x, u8 *y);

#endif