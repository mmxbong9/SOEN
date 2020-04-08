// 09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ConsoleIO.h"
#include "Precalculation.h"
#include "Sokoban.h"

#define putchxy(x,y,c) { gotoxy(x,y); putch(c); }

namespace SOEN
{
	void ExecuteCircleMovement()
	{
		const int xOffset = 20;
		const int yOffset = 10;

		double curAngle;
		int x = -1, y = -1;

		gotoxy(40, 12);
		putch('S');
		for (curAngle = 0; ; curAngle += 10)
		{
			if (curAngle == 360)
			{
				curAngle = 10;
			}

			if (kbhit())
			{
				break;
			}

			gotoxy(40 + x, 12 + y);
			putch(' ');

			x = int(cos(curAngle * 3.1416 / 180) * xOffset);
			y = int(sin(curAngle * 3.1416 / 180) * yOffset);
			gotoxy(40 + x, 12 + y);
			putch('E');
			delay(100);
		}
	}

	void ExecutePrecalculationCircleMovement()
	{
		double curAngle;
		int x = -1;
		int y = -1;

		/*
		static int arx[36] = { 20, 19, 18, 17, 15, 12, 9, 6, 3, 0, -3, -6,
			-10, -12, -15, -17, -18, -19, -19, -19, -18, -17, -15,
			-12, -9, -6, -3, 0, 3, 6, 10, 12, 15, 17, 18, 19 };

		static int ary[36] = { 0, 1, 3, 5, 6, 7, 8, 9, 9, 9, 9, 9,
			8, 7, 6, 4, 3, 1, 0, -1, -3, -5, -6, -7,
			-8, -9, -9, -9, -9, -9, -8, -7, -6, -4, -3, -1 };
		*/

		static int arx[36];
		static int ary[36];

		const double xOffset = 20;
		const double yOffset = 10;

		for (int i = 0; i < 36; i++)
		{
			int tempAngle = i * 10;

			if (tempAngle == 360)
			{
				tempAngle = 10;
			}

			int tempXPos = int(cos(tempAngle * 3.1416 / 180) * xOffset);
			int tempYPos = int(sin(tempAngle * 3.1416 / 180) * yOffset);

			//printf("Calculating X Position : %d to %d | ", arx[i], tempXPos);
			//printf("Calculating Y Position : %d to %d \n", ary[i], tempYPos);

			arx[i] = int(cos(tempAngle * 3.1416 / 180) * xOffset);
			ary[i] = int(sin(tempAngle * 3.1416 / 180) * yOffset);
		}

		gotoxy(40, 12);
		putch('S');
		for (curAngle = 0;; curAngle += 10)
		{
			if (curAngle == 360)
			{
				curAngle = 10;
			}

			if (kbhit())
			{
				break;
			}

			gotoxy(40 + x, 12 + y);
			putch(' ');

			int index = (int)curAngle / 10;
			x = arx[index];
			y = ary[index];
			gotoxy(40 + x, 12 + y);
			putch('E');
			delay(100);
		}
	}
}

namespace SOEN
{
	void DrawScreen()
	{
		int x, y;
		for (y = 0; y < 18; y++)
		{
			for (x = 0; x < 20; x++)
			{
				putchxy(x, y, ns[y][x]);
			}
		}
		putchxy(nx, ny, '@');

		gotoxy(40, 2); puts("SOKOBAN");
		gotoxy(40, 4); puts("Q:종료, R:다시시작");
		gotoxy(40, 6); puts("N:다음, P:이전");
		gotoxy(40, 8); printf("스테이지 : %d", nStage+1);
		gotoxy(40, 10); printf("이동회수 : %d", nMove);
	}

	bool TestEnd()
	{
		int x, y;

		for (y = 0; y < 18; y++)
		{
			for (x = 0; x < 20; x++)
			{
				if (arStage[nStage][y][x] == '.' && ns[y][x] != 'O')
				{
					return false;
				}
			}
		}

		return true;
	}

	void Move(int dir)
	{
		int dx = 0, dy = 0;

		switch (dir)
		{
		case LEFT:
			dx = -1;
			break;
		case RIGHT:
			dx = 1;
			break;
		case UP:
			dy = -1;
			break;
		case DOWN:
			dy = 1;
			break;
		}

		if (ns[ny + dy][nx + dx] != '#') {
			if (ns[ny + dy][nx + dx] == 'O') {
				if (ns[ny + dy * 2][nx + dx * 2] == ' ' || ns[ny + dy * 2][nx + dx * 2] == '.')
				{
					if (arStage[nStage][ny + dy][nx + dx] == '.')
					{
						ns[ny + dy][nx + dx] = '.';
					}
					else
					{
						ns[ny + dy][nx + dx] = ' ';
					}
					ns[ny + dy * 2][nx + dx * 2] = 'O';
				}
				else
				{
					return;
				}
			}
			nx += dx;
			ny += dy;
			nMove++;
		}
	}

	void StartGameSokoban()
	{
		int ch;
		int x, y;

		setcursortype(NOCURSOR);
		nStage = 0;

		for (; 1;)
		{
			memcpy(ns, arStage[nStage], sizeof(ns));
			for (y = 0; y < 18; y++)
			{
				for (x = 0; x < 20; x++)
				{
					if (ns[y][x] == '@')
					{
						nx = x;
						ny = y;
						ns[y][x] = ' ';
					}
				}
			}
			system("cls");
			nMove = 0;

			for (; 2;)
			{
				DrawScreen();
				ch = getch();
				if (ch == 0xE0 || ch == 0)
				{
					ch = getch();
					switch (ch)
					{
					case LEFT:
					case RIGHT:
					case UP:
					case DOWN:
						Move(ch);
						break;
					}
				}
				else
				{
					ch = tolower(ch);
					if (ch == 'r')
					{
						break;
					}

					if (ch == 'p')
					{
						if (nStage > 0)
						{
							nStage--;
						}
						break;
					}

					if (ch == 'q')
					{
						setcursortype(NORMALCURSOR);
						exit(0);
					}
				}

				if (TestEnd())
				{
					system("clr");
					gotoxy(10, 10);
					printf("%d 스테이지를 풀었습니다. 다음 스테이지로 이동합니다.", nStage+1);
					delay(2000);
					if (nStage < MAXSTAGE - 1)
					{
						nStage++;
					}
					break;
				}
			}
		}
	}
}

using namespace SOEN;

int main()
{
    std::cout << "SOEN 9. Array\n";

    //std::cout << "Start Circle Movement\n";
    //ExecuteCircleMovement();
    //ExecutePrecalculationCircleMovement();

    std::cout << "Sokoban Game.\n";
    StartGameSokoban();
}
