#include "SolutionDisplayer.h"
#include "Conf.h"
#include "Point.h"
#include "PrintHelper.h"
#include "Sensor.h"
#include <list>
#include <iterator>
using namespace std;

SolutionDisplayer::SolutionDisplayer(House curHouse,list<Direction>& lstDir)
	:house(curHouse),movesList(lstDir)
{
	this->ptrPrintHelp = PrintHelper(&house);
}

void SolutionDisplayer::StartDisplay()
{
	this->curLocation = house.getFirstDockingLocation();
	list<Direction>::const_iterator iterator;

	for (iterator = this->movesList.begin(); iterator != this->movesList.end(); ++iterator)
	{

		this->ptrPrintHelp.PrintPoint(curLocation, VACUUM_CHAR);
		
	    SensorInformation sensorInfo = house.Sense(this->curLocation);

		if (sensorInfo.isWall[WallInfo::North])
			ptrPrintHelp.PrintPoint(Point(curLocation.getX(), curLocation.getY() - 1), 'W');
		if (sensorInfo.isWall[WallInfo::South])
			ptrPrintHelp.PrintPoint(Point(curLocation.getX(), curLocation.getY() + 1), 'W');
		if (sensorInfo.isWall[WallInfo::West])
			ptrPrintHelp.PrintPoint(Point(curLocation.getX() - 1, curLocation.getY()), 'W');
		if (sensorInfo.isWall[WallInfo::East])
			ptrPrintHelp.PrintPoint(Point(curLocation.getX() + 1, curLocation.getY()), 'W');
		
		Sleep(500);
		this->ptrPrintHelp.PrintPoint(curLocation, house.getPointInfo(curLocation));
		this->moveByDirection(*iterator);
		house.Clean(curLocation);
	}
}

void SolutionDisplayer::moveByDirection(Direction direction)
{
	switch (direction)
	{
		case (Direction::North) :
			curLocation.setY(curLocation.getY() - 1);
			break;
		case (Direction::South) :
			curLocation.setY(curLocation.getY() + 1);
			break;
		case (Direction::East) :
			curLocation.setX(curLocation.getX() + 1);
			break;
		case (Direction::West) :
			curLocation.setX(curLocation.getX() - 1);
			break;
		case (Direction::Stay) :
			break;
	}
}