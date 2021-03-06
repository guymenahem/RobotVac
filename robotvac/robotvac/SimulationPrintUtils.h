#ifndef _SIMUlATIONPRINTUTILS_H_
#define _SIMUlATIONPRINTUTILS_H_
#include "Conf.h"
#include <list>
#include "Point.h"
#include "ConsoleUtils.h"
#include <iostream>

class SimulationPrintUtils
{
public:
	static void printInitialMenu();
	static void printSecondaryMenu();
	static void printSelectHouseMenu(list<string> lst);
	static void printSelectSaved(list<string> lst);
	static void printFileNotFound();
	static void printSavedNotFound();
	static void printMaxStepsDone();
	static void printBatteryDied();
	static void printFinishLastHouse();
	static void printSaveMenu();
	static void clearSecondaryMenu();
	static void SimulationPrintUtils::printSaveOverrideMenu();
	static void printRoundDetails(string houseNum, int roundNum,
		int totalDustInHouse,
		int totalCollected, int batteryState, int maxSteps);
	static void printInsruction();
	static void printScore(int score);
	static void printInvalidStep();
	static void printInvalidHouse(HouseValidation invalidProblem);

	// house printing related stuff

	static void printPointOnMovedHouse(int rows,
		int cols,
		Point& point,
		Point& dockingStation,
		char charToPrint);

	static void printMovedHouse(char** house,
		int rows,
		int cols,
		Point& dockingStation);

};

#endif