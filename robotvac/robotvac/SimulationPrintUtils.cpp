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
	gotoxy(0, 25);
	cout << EMPTY_LINE;
	gotoxy(0, 25);
	cout << "1-continue " << "2-restart " << "3-go to main menu " << " 4-save game"<< " 9-exit " << endl;
}

void SimulationPrintUtils::printSaveMenu()
{
	gotoxy(0, 25);
	cout << EMPTY_LINE;
	gotoxy(0, 26);
	cout << EMPTY_LINE;
	gotoxy(0, 25);
	cout << "Please enter name for game save:" << endl;
}

void SimulationPrintUtils::printSaveOverrideMenu()
{
	gotoxy(0, 25);
	cout << EMPTY_LINE;
	gotoxy(0, 26);
	cout << EMPTY_LINE;
	gotoxy(0, 25);
	cout << "Are you sure you want to override the saved game? 1 - YES     2 - NO" << endl;
}

void SimulationPrintUtils::clearSecondaryMenu()
{
	gotoxy(0, 25);
	cout << EMPTY_LINE;
	gotoxy(0, 26);
	cout << EMPTY_LINE;
	gotoxy(0, 27);
	cout << EMPTY_LINE;
}

void SimulationPrintUtils::printRoundDetails(int roundNum, int totalDustInHouse, int totalCollected, int batteryState)
{
	gotoxy(0, 25);
	cout << EMPTY_LINE;
	gotoxy(0, 25);
	cout << "Round num= " << roundNum << " total dust in house= " << totalDustInHouse
		<< " total collected= " << totalCollected << " battery State= " << batteryState;
}

void SimulationPrintUtils::printScore(int score)
{
	gotoxy(0, 25);
	cout << EMPTY_LINE;
	gotoxy(0, 25);
	cout << "simulation ended! the score is:" << score << endl;
}

void SimulationPrintUtils::printInsruction()
{
	cout << "use 'w' - for up" << endl;
	cout << "use 'a' - for left" << endl;
	cout << "use 'd' - for right" << endl;
	cout << "use 'x' - for down" << endl;
	cout << "use 's' - for stay" << endl;
	cout << "make sure your keyboard is on english" << endl;
	cout << "Press any key to continue";
}

void SimulationPrintUtils::printInvalidStep()
{
	gotoxy(0, 25);
	cout << EMPTY_LINE;
	gotoxy(0, 25);
	cout << "vauum cleaner made invalid step! game is over";
}

void SimulationPrintUtils::printInvalidHouse(HouseValidation invalidProblem)
{
	gotoxy(0, 25);
	cout << EMPTY_LINE;
	gotoxy(0, 25);

	switch (invalidProblem)
	{
	case HouseValidation::InvalidSize:
		cout << "House is not valid - invlalid size" << endl;
		break;

	case HouseValidation::TooMuchDociking:
		cout << "House is not valid - too much docking in the house" << endl;
		break;

	case HouseValidation::NoDocking:
		cout << "House is not valid - docking not found" << endl;
		break;

	default:
		cout << "House is not valid" << endl;
		break;
	}
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


	int x = (point.getX() + offsetX) % cols;
	x = x < 0 ? cols + x : x;
	int y = (point.getY() + offsetY) % rows;
	y = y < 0 ? rows + y : y;

	// go to x,y on screen
	gotoxy(startXPrintingLocation + x, startYPrintingLocation + y);

	cout << charToPrint;
}

void SimulationPrintUtils::printMovedHouse(char** house,
	int rows,
	int cols,
	Point& dockingStation)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			// we put the house in the center of the screen always
			int startYPrintingLocation = (12 - (rows / 2));
			startYPrintingLocation = startYPrintingLocation > 13 ? startYPrintingLocation - 3 : startYPrintingLocation;
			int startXPrintingLocation = (40 - (cols / 2));

			// offset to put the according to docking station in 40,12
			int offsetX = 40 - (dockingStation.getX() + startXPrintingLocation);
			int offsetY = 12 - (dockingStation.getY() + startYPrintingLocation);

			int x = (j + offsetX) % cols;
			x = x < 0 ? cols + x : x;
			int y = (i + offsetY) % rows;
			y = y < 0 ? rows + y : y;

			// go to x,y on screen
			gotoxy(startXPrintingLocation + x, startYPrintingLocation + y);

			cout << house[i][j];
		}
	}
}