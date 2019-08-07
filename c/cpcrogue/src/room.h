typedef struct Room {
  u8 x1, y1;
  u8 x2, y2;
} Room;

void _RoomCreate (Room *r, u8 x, u8 y, u8 w, u8 h);
void _PlaceRoom (Room *r);
u8 _RoomOverlaps (Room *r, Room *other);
void _GetCenter (Room *r, u8 *x, u8 *y);