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


void do_action(enum action key, struct game_data *data)
{
    u_int8_t *x = &data->cursor_x;
    u_int8_t *y = &data->cursor_y;
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
                if (*y > 0) {
                    --(*y);
                }
            }
            break;
        case MV_DOWN:
            {
                if (*y < data->rows - 1) {
                    ++(*y);
                }
            }
            break;
        case MV_LEFT:
            {
                if (*x > 0) {
                    --(*x);
                }
            }
            break;
        case MV_RIGHT:
            {
                if (*x < data->columns - 1) {
                    ++(*x);
                }
            }
            break;
        default:
            break;
    }

}