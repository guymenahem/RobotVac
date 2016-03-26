#include "SimulationPrintUtils.h"
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

void SimulationPrintUtils::printInitialHouseSimulation(char** house,
	int rows,
	int cols,
	Point& dockingStation)
{
	clear_screen();
	printPointOnMovedHouse(house, rows, cols, dockingStation, dockingStation, false, '@');
}

void SimulationPrintUtils::printPointOnMovedHouse(char** house,
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

void SimulationPrintUtils::printPointOnMovedHouse(int rows,
	int cols,
	Point& point,
	Point& dockingStation,
	char charToPrint)
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

	cout << charToPrint;
}

//void House::printMovedHouse(const char house[][MAX_COL + 1], int rows, int cols) {
//	// this part is for debug only, you don't actually need to print the column numbers...
//	//cout << endl;
//	//cout << "          1         2         3         4         5         6         7         " << endl;
//	//cout << "01234567890123456789012345678901234567890123456789012345678901234567890123456789" << endl;
//	//cout << endl;
//
//	int startYPrintingLocation = (12 - (rows / 2));
//	startYPrintingLocation = startYPrintingLocation > 13 ? startYPrintingLocation - 3 : startYPrintingLocation;
//	int startXPrintingLocation = (40 - (cols / 2));
//	Point docking = findDockingStation(house, rows, cols);
//	int offsetX = 40 - (docking.getX() + startXPrintingLocation);
//	int offsetY = 12 - (docking.getY() + startYPrintingLocation);
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			int x = (j - offsetX) % cols;
//			x = x < 0 ? cols + x : x;
//			int y = (i - offsetY) % rows;
//			y = y < 0 ? rows + y : y;
//			gotoxy(startXPrintingLocation + j, startYPrintingLocation + i);
//			cout << house[y][x];
//		}
//
//		cout << "\0" << endl;
//	}
//}
