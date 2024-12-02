#include "window.h"
#include "data.h"
#include <stdio.h>
#include <ncurses.h>


void print(struct game_data *data, WINDOW *win)
{
	//in row 0 print rows x columns and number of mines
	mvwprintw(win, 0, 0, "rows: %d, columns: %d, mines: %d", data->rows, data->columns, (data->rows*data->columns)*15/100 + 1);

	for (int i = 0; i < data->rows; ++i) {
		for (int j = 0; j < data->columns; ++j) {
			if (data->intern_board[i*data->columns + j] & 0b00100000) {
				if (data->intern_board[i*data->columns + j] & 0b10000000) {
					mvwaddch(win, i+2, j, 'X');
				} else {
					char num = (data->intern_board[i*data->columns + j] & 0b00001111) + '0';

					if (num == '0') {
						wattron(win, COLOR_PAIR(2));
						mvwaddch(win, i+2, j, ' ');
						wattroff(win, COLOR_PAIR(2));
					} else {
						wattron(win, COLOR_PAIR(4));
						mvwaddch(win, i+2, j, num);
						wattroff(win, COLOR_PAIR(4));
					}
				}
			} else {
				if (data->intern_board[i*data->columns + j] & 0b01000000) {
					wattron(win, COLOR_PAIR(3));
					mvwaddch(win, i+2, j, '?');
					wattroff(win, COLOR_PAIR(3));
				} else { 
					wattron(win, COLOR_PAIR(1));
					mvwaddch(win, i+2, j, '#');
					wattroff(win, COLOR_PAIR(1));
				}
			}
		}
	}
}