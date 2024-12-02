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
	struct q_data *first, *last;
	u_int16_t elements;
};

struct queue create_queue();

void add_element_queue(struct queue *q, u_int8_t x, u_int8_t y);

void delete_element(struct queue *q);

struct q_data* read_element(struct queue *q);

u_int8_t q_empty(struct queue *q);

enum action {
	CLICK,
	FLAG,
	MV_UP,
	MV_DOWN,
	MV_LEFT,
	MV_RIGHT,
	NONE
};

#endif
