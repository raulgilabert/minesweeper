#ifndef __GAME_H__
#define __GAME_H__

#include <sys/types.h>

#include "data.h"

struct game_data create_board(int rows, int columns);

void add_mine(struct game_data *data);

void click(int x, int y, struct game_data *data);

#endif
