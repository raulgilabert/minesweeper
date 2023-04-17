#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include "explosion.h"
#include "game.h"
#include "window.h"
#include "data.h"

int
main(int argc, char *argv[])
{
	//print_explosion();
	srand(time(NULL));

	int rows = 10, columns = 20;

	struct game_data data = create_board(rows, columns);

	printf("rows: %d, columns: %d\n", rows, columns);

	while (1) {
		//print_debug(&data);
		print(&data);

		printf("> ");

		char command[20];
		scanf("%1s", command);
		
		if (command[0] == 'c') {
			/* click */
			char first_cell[3], second_cell[3];

			scanf("%2s", first_cell);
			scanf("%2s", second_cell);

			int action = click(atoi(first_cell), atoi(second_cell), &data);

			if (action == 2) {
				print(&data);
				print_explosion();
				exit(0);
			}

		} else if (command[0] == 'f') {
			/* flag */
			char first_cell[3], second_cell[3];

			scanf("%2s", first_cell);
			scanf("%2s", second_cell);

			flag(atoi(first_cell), atoi(second_cell), &data);
		} else if (command[0] == 'e') {
			/* exit */
			exit(0);
		} 
	}
}
