#include "game.h"
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

struct game_data
create_board(int rows, int columns)
{
	struct game_data data;
	u_int8_t *board = malloc(sizeof(u_int8_t)*columns*rows);

	data.rows = rows;
	data.columns = columns;
	
	int qtt = (columns*rows)*15/100 + 1; /* proporción de 15% de casillas
					      * con mina + 1 extra en caso de
					      * que hayan menos de 15 casillas
					      */

	for (int i = 0; i < columns*rows; ++i) {
		board[i] = 0;
	}

	data.intern_board = board;

	for (int i = 0; i < qtt; ++i) {
		add_mine(&data);
	}


	return data;
}

void
add_mine(struct game_data *data)
{
	/* generar posición aleatoria en el mapa */
	int pos_y = rand()%(*data).rows;
	int pos_x = rand()%(*data).columns;

	data->intern_board[pos_y*data->columns + pos_x] = 0b10000000;
		
	/* relleno de casillas contiguas a la mina */
	for (int i = -1; i < 2; ++i) {
		/* recorrido de filas contiguas */
		for (int j = -1; j < 2; ++j) {
			/* recorrido de columnas contiguas */
			if (pos_y + i < 0 || pos_y + i >= data->rows ||
			    pos_x + j < 0 || pos_x + j >= data->columns ||
			    (data->intern_board[(pos_y + i)*data->columns +
			    pos_x + j] & 0b10000000) == 1) {
				continue;
			}

			data->intern_board[(pos_y + i)*data->columns + pos_x
			 		     + j] += 0b00000001;
		}
	}
}

void
click(int x, int y, struct game_data *data)
{
	if (x < 0 || x >= data->columns || y < 0 || y >= data->rows) {
		printf("posición no válida\n");
		return;
	}

	if (data->intern_board[y*data->columns + x] & 0b00100000) {
		printf("posición limpia\n");
		return;
	}

	data->intern_board[y*data->columns + x] |= 0b00100000;

	struct queue next_cells;


}
