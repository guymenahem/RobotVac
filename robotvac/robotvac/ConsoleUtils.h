#ifndef _CONSOLEUTILS_H_
#define _CONSOLEUTILS_H_
// you must have a config file, both for windows and for compiling on Linux (MAMA)
// BUT, you need to change the content of the config!
#include "Conf.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y);
void hideCursor();
void clear_screen();

#ifndef WINDOWS	
int _getch(void);
int _kbhit(void);
void Sleep(unsigned long);
void _itoa_s(unsigned int, char s[], unsigned int, int);
#else
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#endif

#endif