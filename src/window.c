#include "window.h"
#include "data.h"
#include <stdio.h>
#include <ncurses.h>


void set_colors()
{
	start_color();

	// 1: game board no clicked
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	// 2: game board clicked and clear
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	// 3: game board clicked and flag
	init_pair(3, COLOR_WHITE, COLOR_GREEN);
	// 4: game board clicked and number
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
}

void print(struct game_data *data, WINDOW *win)
{
	//in row 0 print rows x columns and number of mines
	mvwprintw(win, 0, 0, "rows: %d, columns: %d, mines: %d", data->rows, data->columns, (data->rows*data->columns)*15/100 + 1);
	mvwprintw(win, 1, 0, "player pos: x=%d, y=%d", data->cursor_x, data->cursor_y);

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