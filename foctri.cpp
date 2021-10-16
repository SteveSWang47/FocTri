#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int c[9], pla, as;

int main(int argc, char **argv)
{
    initscr();
    curs_set(0);
    raw();
    keypad(stdscr, TRUE);
    while(1)
    {
        memset(c, 0, sizeof(c));
        srand(time(NULL));
        for(int i = 1; i <= 9; i++)
        {
            do{pla = rand() % 9;}while(c[pla]);
            c[pla] = i;
        }
        clear();
        mvprintw(0,0,"%d",as);
        mvprintw(LINES/2-2, COLS/2-2, "%d %d %d", c[0], c[1], c[2]);
        mvprintw(LINES/2, COLS/2-2, "%d %d %d", c[3], c[4], c[5]);
        mvprintw(LINES/2+2, COLS/2-2, "%d %d %d", c[6], c[7], c[8]);
        refresh();
        char t = getch();
        as++;
        if(t == 'q') break;
    }
    endwin();
    return 0;
}
