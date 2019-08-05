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
#define MAP_HEIGHT      20

// Where the visible map starts, these offsets are added to
// everything we draw so they appear in the correct playable coordinates
#define PLAY_X            1
#define PLAY_Y            2

// Game Sprites
#define   SPR_WALL    '#'
#define   SPR_FLOOR   '.'
#define   SPR_PLAYER  '@'
#define   SPR_GOBLIN  'g'

// Sprite Colors
#define   INK_DARK_TILE   1
#define   INK_LIGHT_TILE  13
#define   INK_ENTITY      20
#define   PEN_ENTITY      1
#define   PEN_TILE        2
#define   PEN_EXLORED     3

// Available actions for player
typedef enum TAction {
  NONE, PLAYER_MOVE
} TAction;

// Possible states in game
typedef enum TState {
  PLAYER_TURN, ENEMY_TURN
} TState;

#endif