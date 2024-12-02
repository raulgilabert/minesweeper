#include <ncurses.h>
#include <stdlib.h>

#include "action.h"
#include "data.h"
#include "game.h"
#include "explosion.h"

enum action read_keyboard()
{
    int ch = getch();

    switch (ch) {
        case 'c':
            return CLICK;
        case 'f':
            return FLAG;
        case KEY_UP:
        case 'w':
            return MV_UP;
        case KEY_DOWN:
        case 's':
            return MV_DOWN;
        case KEY_LEFT:
        case 'a':
            return MV_LEFT;
        case KEY_RIGHT:
        case 'd':
            return MV_RIGHT;
        default:
            return NONE;
    }
}


void do_action(enum action key, int *x, int *y, struct game_data *data)
{
    switch (key) {
        case CLICK:
            {
                int v = click(*x, *y, data);
                if (v == 2) {
                    endwin();
                    print_explosion();
                    exit(0);
                }
            }
            break;
        case FLAG:
            {
                flag(*x, *y, data);
            }
            break;
        case MV_UP:
            {
                --(*y);
            }
            break;
        case MV_DOWN:
            {
                ++(*y);
            }
            break;
        case MV_LEFT:
            {
                --(*x);
            }
            break;
        case MV_RIGHT:
            {
                ++(*x);
            }
            break;
        default:
            break;
    }

}