#ifndef __ACTION_H__
#define __ACTION_H__

#include <ncurses.h>

#include "data.h"

enum action read_keyboard();
void do_action(enum action key, int *x, int *y, struct game_data *data);

#endif