#include <time.h>
#include <windows.h>
#include "MoveChar.h"

#define delay(n) Sleep(n)

namespace SOEN
{
	void clrscr()
	{
		system("cls");
	}

	void gotoxy(int x, int y)
	{
		COORD Cur;
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	}

	int wherex()
	{
		CONSOLE_SCREEN_BUFFER_INFO BufInfo;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
		return BufInfo.dwCursorPosition.X;
	}

	int wherey()
	{
		CONSOLE_SCREEN_BUFFER_INFO BufInfo;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
		return BufInfo.dwCursorPosition.Y;
	}

	void setcursortype(CURSOR_TYPE c)
	{
		CONSOLE_CURSOR_INFO CurInfo;

		switch (c)
		{
		case NOCURSOR:
			CurInfo.dwSize = 1;
			CurInfo.bVisible = FALSE;
			break;
		case SOLIDCURSOR:
			CurInfo.dwSize = 100;
			CurInfo.bVisible = TRUE;
			break;
		case NORMALCURSOR:
			CurInfo.dwSize = 20;
			CurInfo.bVisible = TRUE;
			break;
		}
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
	}
}
