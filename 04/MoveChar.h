#pragma once

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
// enum class CURSOR_TYPE { NOCURSOR, SOLIDCURSOR, NORMALCURSOR }; // C++ scopped enum.

namespace SOEN
{
	void clrscr();
	void gotoxy(int x, int y);
	int wherex();
	int wherey();
	void setcursortype(CURSOR_TYPE c);
}
