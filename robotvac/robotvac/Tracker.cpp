#include "Tracker.h"

void Tracker::initTracker(House _house, KeyboardAlgo* _algo)
{
	this->house = _house;
	curLocation = this->house.getFirstDockingLocation();
	dockLocation = curLocation;
	algo = _algo;
	score = 0;
	abortGame = false;
	battery = BATTERY_CAPACITY;
	numOfSteps = 0;
	numOfCleared = 0;
	printHelper = PrintHelper(&(house), &(dockLocation));
	Sensor* newSens = new Sensor(&(house), &(curLocation));
	algo->setSensor(newSens);
	algo->setPrintHelper(&printHelper);
}


void Tracker::step()
{
	Direction direction = this->algo->step();

	if (checkValidStep(direction))
	{
		// Update console by last location
		this->printHelper.PrintPoint(curLocation, house.getPointInfo(curLocation));

		// make the move & Update vars
		this->moveByDirection(direction);
		this->numOfSteps++;
		this->battery -= BATTERY_CONSUMPTION_RATE;

		// Clean the dirt
		if (house.Clean(curLocation))
		{
			numOfCleared++;
		}

		// Recharge battery if on Docking
		if (house.isDocking(curLocation))
		{
			battery += BATTERY_RECHARGE_RATE;
		}
	}
	else
	{
		this->abortGame = true;

		// Delete @ last location
		this->printHelper.PrintPoint(curLocation, house.getPointInfo(curLocation));

		// Move to new place
		this->moveByDirection(direction);

		// Print X on crash place
		this->printHelper.PrintPoint(curLocation,'X');

		// TODO : print to message bar - Invalid step
	}
}

// Check if game is finished
bool Tracker::isGameFinished()
{
	// Check if battery is empty
	if (battery <= 0)
	{
		this->printHelper.PrintPoint(curLocation, '@');
		return true;
	}

	// Check if house is clean and is on docking
	if (this->house.isHouseClean() && house.isDocking(curLocation))
	{
		this->printHelper.PrintPoint(curLocation, '@');
		return true;
	}

	// Check if done more then max steps
	if (this->numOfSteps >= MAX_STEPS)
	{
		this->printHelper.PrintPoint(curLocation, '@');
		return true;
	}

	// Check if abort game flag is on
	if (this->abortGame)
		return true;

	return false;
}

bool Tracker::checkValidStep(Direction direction)
{
	switch (direction)
	{
	case (Direction::North) :
		return (this->house.getPointInfo(Point(curLocation.getX(), curLocation.getY() - 1)) == WALL) ? false : true;
	case (Direction::South) :
		return (this->house.getPointInfo(Point(curLocation.getX(), curLocation.getY() + 1)) == WALL) ? false : true;
	case (Direction::East) :
		return (this->house.getPointInfo(Point(curLocation.getX() + 1, curLocation.getY())) == WALL) ? false : true;
	case (Direction::West) :
		return (this->house.getPointInfo(Point(curLocation.getX() - 1, curLocation.getY())) == WALL) ? false : true;
	case (Direction::Stay) :
		return true;
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
		curLocation.setX(curLocation.getX() - 1);
		break;
	case (Direction::Stay) :
		break;
	}
}
