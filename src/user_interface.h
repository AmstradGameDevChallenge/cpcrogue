/*!
 * \defgroup user_interface
 *
 * \brief Routines to draw visible game elements
 *
 * The functions in this module are responsible for drawing different
 * elements of the game:
 *
 *  - HUD decorations
 *  - Map world
 *  - Status window (messages)
 *  - Stats window
 *
 */
/**@{*/

/*! \brief Draws the HUD decorations */
void DrawHUD ();

/*! \brief Draws the *stats* window */
void PrintStats (TEntity *e);

/*! \brief Displays a 'loading...' message in the status window */
void DisplayLoading ();

/*! \brief
 * Clears the status message window from *start_line* up to *nlines* lines.
 */
void ClearStatus (u8 start_line, u8 nlines);

/*! \brief Draw the visible elements in the game */
void DrawGame (TEntity *player, u8 left, u8 top, u8 draw_flags);