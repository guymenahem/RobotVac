
#include "Config.h"
#include "ConsoleUtils.h"

using namespace std;

char House[][MAX_COL + 1] = {
	//             1         2         3         4         5         6         7        
	//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
	"W  99   D              1234321                                                 W", // 1
	"W  99      WWWWWWW     1234321                     W                       1   W", // 2
	"W              W                                   W   555                 2   W", // 3
	"W              W                                   W   555                 3   W", // 4
	"W              W           WWWWWWWWWWWWWWWWWWWWWWWWW                       4   W", // 5
	"W              W                                                           5   W", // 6
	"W              W                                                           6   W", // 7
	"W                          WWWWWWWWWWWWWWWWWWWWWW  WWWWWWW                 7   W", // 8
	"W         1         2         3         4         5W 999 W  6         7        W", // 9
	"W              W           444                     W 999 W                 9   W", // 10
	"W              W           444                     W 999 W                 8   W", // 11
	"W              W                                   W     W                 7   W", // 12
	"W              W                                   WW   WW                 6   W", // 13
	"W              W                                    W   W                  5   W", // 14
	"W              W                                                           4   W", // 15
	"W              W                                                           3   W", // 16
	"W              W                                                               W", // 17
	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 18
};

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
