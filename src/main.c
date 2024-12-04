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

	set_colors();

	int x, y;
	getmaxyx(stdscr, y, x);

	int start_x = (x - columns)/2;
	int start_y = (y - rows)/2;

	WINDOW *win = newwin(rows+2, columns, start_y, start_x);

    data.cursor_y = 0;
    data.cursor_x = 0;
    wmove(win, data.cursor_y + 1, data.cursor_x);

    print(&data, win);
    wrefresh(win);

	while (1)
	{

		print(&data, win);

		wmove(win, data.cursor_y+2, data.cursor_x);
		wrefresh(win);

		do_action(read_keyboard(), &data);
	}
}
