#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <cstring>

using namespace std;

int c[25], pla, as, tmpt;

int main(int argc, char **argv)
{
    initscr();
    curs_set(0);
    raw();
    keypad(stdscr, TRUE);
    while(1)
    {
        memset(c, 0, sizeof(c));
        srand(tmpt = time(NULL));
        for(int i = 1; i <= 25; i++)
        {
            do{pla = rand() % 25;}while(c[pla]);
            c[pla] = i;
        }
        clear();
        mvprintw(0,0,"%d",as);
        mvprintw(LINES/2-4, COLS/2-6, "%2d %2d %2d %2d %2d", c[0], c[1], c[2], c[3], c[4]);
        mvprintw(LINES/2-2, COLS/2-6, "%2d %2d %2d %2d %2d", c[5], c[6], c[7], c[8], c[9]);
        mvprintw(LINES/2, COLS/2-6, "%2d %2d %2d %2d %2d", c[10], c[11], c[12], c[13], c[14]);
        mvprintw(LINES/2+2, COLS/2-6, "%2d %2d %2d %2d %2d", c[15], c[16], c[17], c[18], c[19]);
        mvprintw(LINES/2+4, COLS/2-6, "%2d %2d %2d %2d %2d", c[20], c[21], c[22], c[23], c[24]);
        refresh();
        char t = getch();
        as++;
        clear();
        if(t == 'q') break;
        mvprintw(0,0,"%d",as);
        mvprintw(LINES/2, 0, "Time: %ds", time(NULL) - tmpt);
        refresh();
        sleep(2);
    }
    endwin();
    return 0;
}
