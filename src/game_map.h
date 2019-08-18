#include "entity.h"
#include "rect.h"


/*!
 * \defgroup GameMap
 *
 * \brief Map creation and query routines
 *
 * The structures and functions in this module helps with the creation and
 * query of the map in the game.
 *
 * The game stores information of each tile in the map. Each tile needs to
 * keep track of certain attributes like is it walkable?, or blocks light?
 * etc.
 *
 */
/**@{*/

/*!
 * \struct  TTile
 *
 * \brief Single tile information
 */
typedef struct {
  u8 t_flags; ///< flag attributes for a specific tile
} TTile;

/*!
 * \struct TMap
 *
 * \brief Map dimensions and tiles it contains
 *
 */
typedef struct {
  u8 width;   ///< Game map width
  u8 height;  ///< Game map height
  TTile tiles[MAP_HEIGHT][MAP_WIDTH]; ///<every single tile in the map
} TMap;

/*!
 * \struct TRoom
 *
 * \brief Rooms in the level.
 *
 * A room is a boxed empty space surrounded by walls. It is mainly used
 * internally to randomly generate the dungeon.
 *
 */
// Room info
typedef struct {
  TRect rect;   ///< x,y, width, height including walls
  u8 grid_id;   ///< Grid id where the room is placed
} TRoom;

/*!
 * \struct TGridCell
 *
 * \brief Grid cell info, used to distribute the rooms
 *
 * The creation of the randomly generated dungeon uses a grid based
 * distribution to ensure no rooms will overlap. This struct keeps info
 * about this grid.
 *
 */
typedef struct {
  u8 x;       ///< left coordinate of the grid cell
  u8 y;       ///< top coordinate of the grid cell
  u8 room_id; ///< room assigned to this grid cell
} TGridCell;

extern TGridCell grid[];  ///< Grid cells
extern TRoom rooms[];     ///< Rooms placed in map

/*!
 * \brief Global variable to access the game map
 */
extern TMap game_map;


/*!
 * \brief Create a new map
 */
void MapCreate (u8 width, u8 height, TEntity *player);

/*!
 * \brief True if specified map coordinates block movement (i.e: wall)
 *
 * \param[in] x,y Map coordinates to query.
 *
 * \returns true if tile blocks movement.
 */
u8 MapIsBlocked (u8 x, u8 y);

/*!
 * \brief True if specified map coordinates block light (i.e: wall)
 *
 * \param[in] x,y Map coordinates to query.
 *
 * \returns true if tile blocks light.
 */
u8 MapBlocksLight (u8 x, u8 y);

/*! \brief Sets area around origin_x/_y to not visible
 */
void MapSetNotVisible (u8 origin_x, u8 origin_y, u8 range);

/*!
 * \brief Draws a visible portion of the map centered around the player
 */
void MapDraw (u8 left, u8 right, u8 width, u8 height, TEntity *player);
void GetView (TEntity* player, u8 *left, u8 *top, u8 width, u8 height);

inline void MapSetVisible (u8 x, u8 y) {
  game_map.tiles[y][x].t_flags |= VISIBLE;
}
