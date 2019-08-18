/*!
 * \defgroup fov
 *
 * \brief Field of View information and management
 *
 * This module keeps track of the visible tiles from a specific position.
 * Most of the work in this module is to perform *LOS* calculation and
 * updating the visibility map information. This information is later used
 * by the \ref user_interface module to draw the map accordingly.
 *
 */
/**@{*/

/*! \brief
 * Resets the visibility map to everything *not visible*
 */
void ClearVisMap ();

/*! \brief
 * Sets a specific tile in the visibility map as visible
 */
void SetVisible (u8 x, u8 y);

/*! \brief
 * Queries a specific visibility map coordinate for visibility
 */
u8 isVisible (u8 x, u8 y);

/*! \brief
 * Traces a line between two game map points and updates the FOV visibility.
 */
void TraceLine (u8 x1, u8 y1, u8 x2, u8 y2, u8 range);

/*! \brief
 * Computes *Light of Sight* from point constrained to a specific
 * range distance
 */
void ComputeLOS (u8 from_x, u8 from_y, u8 range);
