#define VER "v1.2.1"

#include <stdlib.h>
#include <ncurses.h>

int main()
{
    initscr();
    while(1)
    {
        clear();
        mvprintw(0, 0, "FocTri %s", VER);
        mvprintw(1, 0, "1 - 3x3 \"Simple\" mode");
        mvprintw(2, 0, "2 - 5x5 \"Standard\" mode");
        mvprintw(3, 0, "Q - Exit");
        mvprintw(4, 0, ": ");
        refresh();
        char uti = getch();
        if(uti == '1') system("foctri3x3");
        else if(uti == '2') system("foctri");
        else if(uti == 'q') break;
    }
    endwin();
    return 0;
}
