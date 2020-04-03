// 04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "MoveChar.h"

#define getch _getch
#define putch _putch

using namespace SOEN;

int main()
{
    int x;
    int y;

    int ch;

    x = 40;
    y = 10;
    clrscr();

    for (;;)
    {
        gotoxy(0, 0);
        printf("quit : Q, q");
        gotoxy(0, 1);
        printf("Move : ก็ ก่ กๆ ก้");

        gotoxy(x, y);
        putch('#');
        ch = getch();

        if (ch == 0xE0 || ch == 0)
        {
            ch = getch();

            switch (ch)
            {
            case 75:
                x = x - 1;
                break;
            case 77:
                x = x + 1;
                break;
            case 72:
                y = y - 1;
                break;
            case 80:
                y = y + 1;
                break;
            default:
                putch('\a');
                break;
            }
        }
        else
        {
            switch (ch)
            {
            case ' ':
                clrscr();
                break;
            case 'q':
            case 'Q':
                exit(0);
                break;
            default:
                putch('\a');
                break;
            }
        }
    }
}
