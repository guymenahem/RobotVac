#ifndef _SIMUlATIONPRINTUTILS_H_
#define _SIMUlATIONPRINTUTILS_H_
#include "Conf.h"
#include "Point.h"
#include "ConsoleUtils.h"
#include <iostream>

class SimulationPrintUtils
{
public:
	static void printInitialMenu();
	static void printSecondaryMenu();


	// house printing related stuff
	static void printMovedHouse(char** house, int rows, int cols);
	static void printInitialHouseSimulation(char** house,
		int rows,
		int cols,
		Point& dockingStation);

	static void printPointOnMovedHouse(char** house,
		int rows,
		int cols,
		Point& point,
		Point& dockingStation,
		bool isPrintHouseChar, char CharToPrint);

	static void printPointOnMovedHouse(int rows,
		int cols,
		Point& point,
		Point& dockingStation,
		char charToPrint);

};

#endif
