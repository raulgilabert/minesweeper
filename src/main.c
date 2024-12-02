#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>

#include "explosion.h"
#include "game.h"
#include "window.h"
#include "data.h"
#include "action.h"

int
main(int argc, char *argv[])
{
	//print_explosion();
	srand(time(NULL));

	int rows = 12, columns = 35;

	struct game_data data = create_board(rows, columns);

	initscr();
	cbreak();
	noecho();

	if (!has_colors()) {
        endwin();
        printf("El terminal no soporta colores.\n");
        return 1;
    }

	start_color();

	// 1: game board no clicked
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	// 2: game board clicked and clear
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	// 3: game board clicked and flag
	init_pair(3, COLOR_WHITE, COLOR_GREEN);
	// 4: game board clicked and number
	init_pair(4, COLOR_WHITE, COLOR_BLUE);


	int x, y;
	getmaxyx(stdscr, y, x);

	int start_x = (x - columns)/2;
	int start_y = (y - rows)/2;

	WINDOW *win = newwin(rows+2, columns, start_y, start_x);

	wrefresh(win);

	getyx(win, y, x);

	while (1)
	{
		print(&data, win);
		wmove(win, y+2, x);

		wrefresh(win);

		do_action(read_keyboard(), &x, &y, &data);
	}
}
