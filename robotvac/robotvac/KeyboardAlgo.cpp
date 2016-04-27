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
	SensorInformation sensorInfo = ptrSensor->sense();
	this->printSensorInfo(sensorInfo, *(ptrSensor->getCurrentLocation()));

	// Wait for user replay
	Sleep(SLEEP_TIME);

	// check if hit key
	if (_kbhit())
	{
		this->lastKey = _getch();
		this->lastDirection = getDirectinoByKey(this->lastKey);
	}

	// If is going to go on wall, change direction to stay
	if (!checkIfStepIsValid(this->lastDirection, sensorInfo))
	{
		this->lastDirection = Direction::Stay;
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
	case '\x1b': //ESC
		return Direction::Stay;
		break;

	default:
		return this->lastDirection;
	}
}

void KeyboardAlgo::printSensorInfo(struct SensorInformation info, Point location)
{

	// TODO : print current spot (dirtLevel)

	if (info.isWall[WallInfo::North])
		ptrPrintHelp->PrintPoint(Point(location.getX(), location.getY() - 1), 'W');
	if (info.isWall[WallInfo::South])
		ptrPrintHelp->PrintPoint(Point(location.getX(), location.getY() + 1), 'W');
	if (info.isWall[WallInfo::West])
		ptrPrintHelp->PrintPoint(Point(location.getX() - 1, location.getY()), 'W');
	if (info.isWall[WallInfo::East])
		ptrPrintHelp->PrintPoint(Point(location.getX() + 1, location.getY()), 'W');
	ptrPrintHelp->PrintPoint(location, VACUUM_CHAR);
}

void KeyboardAlgo::printCurLocation()
{
	ptrPrintHelp->PrintPoint(*(this->ptrSensor->getCurrentLocation()), VACUUM_CHAR);
}

bool KeyboardAlgo::checkIfStepIsValid(Direction direction, struct SensorInformation sensorInfo)
{
	return !(sensorInfo.isWall[(int)direction]);
}

void KeyboardAlgo::clearHelpers()
{
	delete this->ptrSensor;
}
