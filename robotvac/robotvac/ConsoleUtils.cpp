#include "Conf.h"
#include "ConsoleUtils.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#ifndef WINDOWS
void gotoxy(int x, int y){}
void clear_screen(){}
int _kbhit(void){ return 0; }
void Sleep(unsigned long){}
int _getch(void){ return 0; }
#else

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout << flush;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}


void clear_screen()
{
	system("cls");
}

#endif

