#ifndef CONST_H
#define CONST_H
/****************************************************************************
 * Special ASCII codes
 ***************************************************************************/
#define US  0x1f        // LOCATE
#define FS  0x1c        // INK
#define GS  0x1d        // BORDER
#define SO  0x0e        // PAPER
#define SI  0x0f        // PEN
#define FF  0x0c        // CLS

// Boolean 'aliases'
#define TRUE 1
#define FALSE 0

// Max allowed entities in game
#define MAX_ENTITIES 5

// Map dimensions
#define MAP_WIDTH       28
#define MAP_HEIGHT      18

// Where the visible map starts, these offsets are added to
// everything we draw so they appear in the correct playable coordinates
#define PLAY_X          2
#define PLAY_Y          2
#define STATS_X         PLAY_X + MAP_WIDTH + 1
#define STATS_Y         3
#define STATUS_X        2
#define STATUS_Y        21
#define LOADING_X       STATUS_X
#define LOADING_Y       STATUS_Y

// Game Sprites
#define   SPR_WALL    '#'
#define   SPR_FLOOR   '.'
#define   SPR_PLAYER  '@'
#define   SPR_GOBLIN  'g'

// Sprite Colors
#define   INK_BG          0
#define   INK_DARK        1
#define   INK_BRIGHT      20
#define   INK_NORMAL      10
#define   PEN_ENTITY      3

#define   PEN_CLEAR       0
#define   PEN_TILE        3
#define   PEN_EXLORED     1
#define   PEN_BRIGHT      2
#define   PEN_NORMAL      3

// Available actions for player
typedef enum TAction {
  NONE, PLAYER_MOVE
} TAction;

// Possible states in game
typedef enum TState {
  PLAYER_TURN, ENEMY_TURN
} TState;

#endif