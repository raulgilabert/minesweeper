#ifndef __DATA_H__
#define __DATA_H__

#include <sys/types.h>

struct game_data {
	u_int8_t *intern_board; /* bits: mfcdqqqq
				 * m: mine; f: flag; c: clicked; d: flag doubt;
				 * q: quantity of mines near */
	u_int8_t rows, columns;
};

struct q_data {
	u_int8_t x, y;
	struct q_data *next;
};

struct queue {
	struct q_data *first;
	u_int16_t elements;
};

#endif
