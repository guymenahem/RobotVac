#include "KeyboardAlgo.h"
#include "Sensor.h"
#include "ConsoleUtils.h"


void KeyboardAlgo::setSensor(Sensor* sensor)
{
	this->ptrSensor = sensor;
}

void KeyboardAlgo::setPrintHelper(PrintHelper * _ptrPrintHelp)
{
	ptrPrintHelp = _ptrPrintHelp;
}

Direction KeyboardAlgo::step()
{
	// Sense and Print
	this->printSensorInfo(ptrSensor->sense(), *(ptrSensor->getCurrentLocation()));

	// Wait for user replay
	Sleep(500);
	
	// check if hit key
	if (_kbhit())
	{
		return getDirectinoByKey(_getch());
	}

	return this->lastDirection;
}

Direction KeyboardAlgo::getDirectinoByKey(char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
		return Direction::North;
		break;

	case 'd':
	case 'D':
		return Direction::East;
		break;

	case 'x':
	case 'X':
		return Direction::South;
		break;

	case 'a':
	case 'A':
		return Direction::West;
		break;

	case 's':
	case 'S':
	default:
		return Direction::Stay;
		break;
	}
}

void KeyboardAlgo::printSensorInfo(struct SensorInformation info, Point location)
{
	
	// TODO : print current spot (dirtLevel)

	if (info.isWall[WallInfo::North])
		ptrPrintHelp->PrintPoint(Point(location.getX(), location.getY() - 1 ), 'W');
	if (info.isWall[WallInfo::South])
		ptrPrintHelp->PrintPoint(Point(location.getX(), location.getY() + 1), 'W');
	if (info.isWall[WallInfo::West])
		ptrPrintHelp->PrintPoint(Point(location.getX() - 1, location.getY()), 'W');
	if (info.isWall[WallInfo::East])
		ptrPrintHelp->PrintPoint(Point(location.getX() + 1, location.getY()), 'W');
}
