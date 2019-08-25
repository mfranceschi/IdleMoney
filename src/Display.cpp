#include "Display.h"

Display::Display() 
{
    initscr(); // Init screen and functions.
    move(0, 0);
    printw("==================== IDLE MONEY ====================");
    move(1, 0);
    printw("kk");

    refresh();
}

Display::~Display()
{
    getch();
    endwin();
}
