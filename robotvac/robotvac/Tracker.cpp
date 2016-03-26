#include "Tracker.h"

Tracker::Tracker(House _house, KeyboardAlgo* _algo)
{
	this->house = _house;
	curLocation = this->house.getDockingLocation();
	dockLocation = curLocation;
	algo = _algo;
	score = 0;
	battery = BATTERY_CAPACITY;
	numOfSteps = 0;
	numOfCleared = 0;
	algo->setSensor(new Sensor(&(house), &(curLocation)));
	algo->setPrintHelper(new PrintHelper(&(house), &(dockLocation)));
}


void Tracker::step()
{
	Direction direction = this->algo->step();

	if (checkValidStep(direction))
	{
		// Update console by last location
		printHelper.PrintPoint(curLocation, house.getPointInfo(curLocation));

		// make the move - Update vars
		moveByDirection(direction);
		numOfSteps++;

		if (house.Clean(curLocation))
		{
			numOfCleared++;
		}

		// Update Screen
		printHelper.PrintPoint(curLocation, '@');
	}
	else
	{
		// signal invalid step
		//TODO : abort game
	}
}

// Check if game is finished
bool Tracker::isGameFinished()
{
	if (battery <= 0)
		return true;
	if (this->house.isHouseClean())
		return true;
	if (this->numOfSteps < MAX_STEPS)
		return true;

	return false;
}

bool Tracker::checkValidStep(Direction direction)
{
	switch (direction)
	{
	case (Direction::North) :
		return (this->house.getPointInfo(Point(curLocation.getX(), curLocation.getY()-1)) == WALL) ? false : true;
	case (Direction::South) :
		return (this->house.getPointInfo(Point(curLocation.getX(), curLocation.getY() + 1)) == WALL) ? false : true;
	case (Direction::East) :
		return (this->house.getPointInfo(Point(curLocation.getX() + 1, curLocation.getY())) == WALL) ? false : true;
	case (Direction::West) :
		return (this->house.getPointInfo(Point(curLocation.getX() - 1, curLocation.getY())) == WALL) ? false : true;
	}

	return false;
}

void Tracker::moveByDirection(Direction direction)
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
		curLocation.setY(curLocation.getY() - 1);
		break;
	case (Direction::Stay):
		break;
	}
}
