/****************************************************************************
 *    Line
 *
 * Traces a line from x1,y1 to x2,y2 using Bresenham's algorithm and
 * returns the coordinates as an array coords.
 */
void TraceLine (u8 x1, u8 y1, u8 x2, u8 y2, u8 range);

// Compute Light of Sight from point constrained to
// specific range distance
void ComputeLOS (u8 from_x, u8 from_y, u8 range);