#include "window.h"
#include "data.h"
#include <stdio.h>

void
print(struct game_data *data)
{
	printf(" 0");
	for (int i = 0; i < data->columns - 2; ++i) {
		printf(" ");
	}
	printf("%d\n", data->columns);

	printf("+");
	for (int i = 0; i < data->columns; ++i) {
		printf("-");
	}
	printf("+\n");

	for (int i = 0; i < data->rows; ++i) {
		printf("|");
		for (int j = 0; j < data->columns; ++j) {
			u_int8_t num = data->intern_board[i*data->columns + j];

			char char_to_print = ' ';


			if (num & 0b01000000) {
				char_to_print = 'F';
			} else if (!(num & 0b00100000)) {
				char_to_print = '#';
			} else if (num & 0b10000000) {
				char_to_print = 'B';
			} else if ((num & 0b00001111) == 0) {

			} else {
				char_to_print = '0' + (num & 0b00001111);
			}

			printf("%c", char_to_print);
		}
		printf("|%d\n", i);
	}

	printf("+");
	for (int i = 0; i < data->columns; ++i) {
		printf("-");
	}
	printf("+\n");


}

void
print_debug(struct game_data *data)
{
	printf("+");
	for (int i = 0; i < data->columns; ++i) {
		printf("-");
	}
	printf("+\n");

	for (int i = 0; i < data->rows; ++i) {
		printf("|");
		for (int j = 0; j < data->columns; ++j) {
			u_int8_t num = data->intern_board[i*data->columns + j];

			char char_to_print = ' ';


			if (num & 0b10000000) {
				char_to_print = 'B';
			} else if ((num & 0b00001111) == 0) {

			} else {
				char_to_print = '0' + (num & 0b00001111);
			}

			printf("%c", char_to_print);
		}
		printf("|\n");
	}

	printf("+");
	for (int i = 0; i < data->columns; ++i) {
		printf("-");
	}
	printf("+\n");


}
