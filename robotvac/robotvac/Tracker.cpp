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
	dirtLeftToClean = this->house.getTotalDirtLeft();
	initialAmountOfDirt = dirtLeftToClean;
	printHelper = PrintHelper(&(house), &(dockLocation));
	Sensor* newSens = new Sensor(&(house), &(curLocation));
	algo->setSensor(newSens);
	algo->setPrintHelper(&printHelper);
	returnedToDockingOnFinish = false;
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
			dirtLeftToClean--;
		}

		// Recharge battery if on Docking
		if (house.isDocking(curLocation))
		{
			battery += BATTERY_RECHARGE_RATE;
		}

		SimulationPrintUtils::printRoundDetails(numOfSteps, this->dirtLeftToClean, this->numOfCleared, this->battery);
	}
	else
	{
		this->abortGame = true;
		this->endreason = EndReason::StepIntoWall;

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
		this->endreason = EndReason::BatteryDied;
		return true;
	}

	// Check if house is clean and is on docking
	if (this->house.isHouseClean() && house.isDocking(curLocation))
	{
		this->printHelper.PrintPoint(curLocation, '@');
		this->returnedToDockingOnFinish = true;
		this->endreason = EndReason::FinishClean;
		return true;
	}

	// Check if done more then max steps
	if (this->numOfSteps >= MAX_STEPS)
	{
		this->printHelper.PrintPoint(curLocation, '@');
		this->endreason = EndReason::maxStepsDone;
		return true;
	}

	// Check if abort game flag is on
	if (this->abortGame)
	{
		// this->endreason = EndReason::StepIntoWall - moved the check if direction is not valid
		return true;
	}

	// If user pressed ESC
	if (this->algo->getLastKey() == '\x1b')
	{
		this->algo->clearLastkey();
		SimulationPrintUtils::printSecondaryMenu();
		
		bool selectionMade = false;

		while (_kbhit)
		{
			char key = getch();

			switch (key)
			{
					// just continue
				case '1':
					// Clear the screen the print last house known - maybe in the future
					selectionMade = true;
					return false;
					//break;

					// Restart this house simulation
				case '2':
					clear_screen();
					this->endreason = EndReason::Restart;
					selectionMade = true;
					return true;
					//break;

					// Go to main menu
				case '3':
					this->endreason = EndReason::MainMenu;
					selectionMade = true;
					return true;
					//break;

				// Exit
				case '9':
					clear_screen();
					this->endreason = EndReason::UserAbort;
					selectionMade = true;
					return true;
					//break;
			}
		}
	}
		

	return false;
}

// Check if the step is valid
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

// Move the robot by direction 
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





