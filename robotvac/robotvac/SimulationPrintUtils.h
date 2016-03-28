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
	static void printRoundDetails(int roundNum,
		int totalDustInHouse,
		int totalCollected, int batteryState);
	static void printInsruction();
	static void printScore(int score);
	static void printInvalidStep();
	static void printInvalidHouse();

	// house printing related stuff

	static void printPointOnMovedHouse(int rows,
		int cols,
		Point& point,
		Point& dockingStation,
		char charToPrint);

	static void SimulationPrintUtils::printMovedHouse(char** house,
		int rows,
		int cols,
		Point& dockingStation);

};

#endif