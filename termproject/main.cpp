#include "board.h"
#include <cstdio>
#include <stdio.h>
#include <termio.h>

int getch(void){	//getch가 없어서 인터넷에서 소스 참고하여 구현
    int ch;
    struct termios buf, save;

    tcgetattr(0,&save);
    buf = save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

int b[14][7];

int main()
{
    board* bd = new board();
    char input;
    bd->printBoard();
    while(1)
    {
        bd->create();
        bd->printBoard();
        do{
            do{
                input = getch();
            }while(input!='x'&&input!='a'&&input!='s'&&input!='d'&&input!='e'&&input!='q');
        }while(!bd->move(input));
        bd->explode();
    }

    return 0;
}