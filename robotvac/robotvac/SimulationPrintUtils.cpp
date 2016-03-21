#include "Point.h"
#include "SimulationPrintUtils.h"
#include "ConsoleUtils.h"
#include <iostream>
using  namespace std;

void SimulationPrintUtils::printInitialMenu()
{
	cout << "1-start run" << endl;
	cout << "8-show instructions" << endl;
	cout << "9-exit" << endl;
}
void SimulationPrintUtils::printSecondaryMenu()
{
	cout << "1-continue" << endl;
	cout << "2-restart simulation on this house" << endl;
	cout << "3-go to main menu" << endl;
	cout << "9-exit" << endl;
}

void SimulationPrintUtils::printInitialHouseSimulation(const char house[][MAX_HOUSE_WID],
	int rows,
	int cols,
	Point& dockingStation)
{
	clear_screen();
	printPointOnMovedHouse(house, rows, cols, dockingStation, dockingStation, false, '@');
}

void SimulationPrintUtils::printPointOnMovedHouse(const char house[][MAX_HOUSE_WID],
	int rows,
	int cols,
	Point& point,
	Point& dockingStation,
	bool isPrintHouseChar, char charToPrint)
{
	// we put the house in the center of the screen always
	int startYPrintingLocation = (12 - (rows / 2));
	startYPrintingLocation = startYPrintingLocation > 13 ? startYPrintingLocation - 3 : startYPrintingLocation;
	int startXPrintingLocation = (40 - (cols / 2));

	// offset to put the according to docking station in 40,12
	int offsetX = 40 - (dockingStation.getX() + startXPrintingLocation);
	int offsetY = 12 - (dockingStation.getY() + startYPrintingLocation);


	int x = (point.getX() - offsetX) % cols;
	x = x < 0 ? cols + x : x;
	int y = (point.getY() - offsetY) % rows;
	y = y < 0 ? rows + y : y;

	// go to x,y on screen
	gotoxy(startXPrintingLocation + point.getX(), startYPrintingLocation + point.getY());

	// check if print the point in house or the robot char\other char
	charToPrint = isPrintHouseChar ? house[y][x] : charToPrint;
	cout << charToPrint;
}






