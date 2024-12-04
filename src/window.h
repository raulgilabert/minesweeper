#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <ncurses.h>

#include "game.h"
#include "data.h"

void set_colors();

void print(struct game_data *data, WINDOW *win);

#endif
