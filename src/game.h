#ifndef GAME_H
#define GAME_H

void
NewGame (TEntity **player);

void
GameDraw (TEntity *player,
  u8 *fov_changed, u8 *view_updated, u8 *left, u8 *top, u8 draw_flags);

void
GameDoPlayerTurn (TEntity *player, u8 dx, u8 dy, u8 left, u8 top,
  u8 *log_is_full, u8 *view_updated, u8 *fov_changed);

#endif