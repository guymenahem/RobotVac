#include "Tracker.h"
#include "Menus.h" 
#include "FilesUtils.h"
#include "SolutionDisplayer.h"
#include <string.h>

void Tracker::initTracker(House _house, KeyboardAlgo* _algo)
{
	this->house = _house;
	this->originalHouse = _house;
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
	printHelper = PrintHelper(&(house));
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
		this->addMoveToMovesList(direction);

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
		this->printHelper.PrintPoint(curLocation, VACUUM_CHAR);
		this->endreason = EndReason::BatteryDied;
		return true;
	}

	// Check if house is clean and is on docking
	if (this->house.isHouseClean() && house.isDocking(curLocation))
	{
		this->printHelper.PrintPoint(curLocation, VACUUM_CHAR);
		this->returnedToDockingOnFinish = true;
		this->endreason = EndReason::FinishClean;
		this->saveSolutionIfBest();

		return true;
	}

	// Check if done more then max steps
	if (this->numOfSteps >= MAX_STEPS)
	{
		this->printHelper.PrintPoint(curLocation, VACUUM_CHAR);
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
		return (ShowSecondaryMenu());

	}
		
	return false;
}

bool Tracker::ShowSecondaryMenu()
{
	this->algo->clearLastkey();

	// SimulationPrintUtils::printSecondaryMenu();
	SeconderyMenuState secMenuState = Menus::seconderyMenu();

	switch (secMenuState)
	{
		// just continue
	case SeconderyMenuState::Continue:
		return false;

		// Restart this house simulation
	case SeconderyMenuState::Restart:
		clear_screen();
		this->endreason = EndReason::Restart;
		return true;

		// Go to main menu
	case SeconderyMenuState::MainMenu:
		this->endreason = EndReason::MainMenu;
		return true;

	case SeconderyMenuState::SaveGame:
		this->saveCurrentGame();
		return false;

	case SeconderyMenuState::ShowSolution:
	{
		if (FilesUtils::isThereSolution(this->house.getHouseNumber()))
		{
			showHouseSolution();
		}
		else
		{
			gotoxy(0, 25);
			cout << "no solution was found" << EMPTY_LINE;
			Sleep(1000);
			return (ShowSecondaryMenu());
		}

		return false;
	}
	// Exit
	case SeconderyMenuState::Exit:
		clear_screen();
		this->endreason = EndReason::UserAbort;
		return true;
	}
}

void Tracker::showHouseSolution()
{
	list<string> solutionFromFile = FilesUtils::readSolutionFromFile(this->house.getHouseNumber());
	clear_screen();
	SolutionDisplayer solDisplayer(this->originalHouse, convertSolutionStringListToSolutionDirectionList(solutionFromFile));
	solDisplayer.StartDisplay();
	clear_screen();
	Sleep(500);
	this->restoreHouseGame();
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

void Tracker::addMoveToMovesList(const Direction& dir)
{
	this->movesList.push_back(dir);
}

list<string> Tracker::convertMovesListToMovesStringList()
{
	list<string> lst;
	int directionSequenceCounter = 0;
	Direction curDirSequence = this->movesList.front();

	for each (Direction dir in this->movesList)
	{
		if (dir == curDirSequence)
		{
			directionSequenceCounter++;
		}
		else
		{
			
			lst.push_back(convertDirectionSequenceToString(curDirSequence,directionSequenceCounter));
			directionSequenceCounter = 1;
			curDirSequence = dir;
		}
		
	}
	
	// insert last direction seq to list
	lst.push_back(convertDirectionSequenceToString(curDirSequence, directionSequenceCounter));

	return lst;
}

string Tracker::convertDirectionSequenceToString(Direction dir, int sequenceCount)
{
	string dirString;

	switch (dir)
	{
	case(Direction::East) :
		dirString = 'd';
		break;
	case(Direction::West) :
		dirString = 'a';
		break;
	case(Direction::North) :
		dirString = 'w';
		break;
	case(Direction::South) :
		dirString = 'x';
		break;
	case(Direction::Stay) :
		dirString = 's';
		break;
	default:
		break;
	}
	
	string s = "";
	s.append(to_string(sequenceCount));
	s.append(":");
	s.append(dirString);

	return s;
}

list<Direction> Tracker::convertSolutionStringListToSolutionDirectionList(list<string> solList)
{
	list<Direction> dirList;
	std::list<string>::const_iterator iterator;
	for (iterator = solList.begin(); iterator != solList.end(); ++iterator)
	{
		Direction dir;
		char dirString = iterator->back();
		int numMoves = iterator->front() - '0';
		switch (dirString)
		{
		case('d') :
			dir = Direction::East ;
			break;
		case('a') :
			dir = Direction::West;
			break;
		case('w') :
			dir = Direction::North;
			break;
		case('x') :
			dir = Direction::South;
			break;
		case('s') :
			dir = Direction::Stay;
			break;
		default:
			dir = Direction::Stay;
			break;

		}

		for (int i = 0; i < numMoves; i++)
		{
			dirList.push_back(dir);
		}


	}
	return dirList;
}

void Tracker::saveCurrentGame()
{
	string fileName = Menus::saveGameMenu();
	
	if (FilesUtils::isSavedGameExist(fileName, this->house.getHouseNumber()))
	{
		if (Menus::overrideMenu())
		{
			FilesUtils::writeSaveToFile(this->convertMovesListToMovesStringList(), this->house.getHouseNumber(), fileName);
		}
	}
	else
	{
		FilesUtils::writeSaveToFile(this->convertMovesListToMovesStringList(), this->house.getHouseNumber(), fileName);
	}

	Menus::clearSeconderyMenu();
}

void Tracker::saveSolutionIfBest()
{
	if (!FilesUtils::isThereBetterSol(this->house.getHouseNumber(), this->numOfSteps))
	{
		FilesUtils::writeSoultionToFile(this->convertMovesListToMovesStringList(), this->getNumOfSteps(), this->house.getHouseNumber());
	}
}



void Tracker::restoreHouseGame()
{
	Sleep(600);
	this->initTracker(originalHouse, algo);

	//restore game by dir list
	list<Direction>::const_iterator iterator;
	for (iterator = this->movesList.begin(); iterator != this->movesList.end(); ++iterator)
	{
		SensorInformation sensorInfo = house.Sense(this->curLocation);

		if (sensorInfo.isWall[WallInfo::North])
			printHelper.PrintPoint(Point(curLocation.getX(), curLocation.getY() - 1), 'W');
		if (sensorInfo.isWall[WallInfo::South])
			printHelper.PrintPoint(Point(curLocation.getX(), curLocation.getY() + 1), 'W');
		if (sensorInfo.isWall[WallInfo::West])
			printHelper.PrintPoint(Point(curLocation.getX() - 1, curLocation.getY()), 'W');
		if (sensorInfo.isWall[WallInfo::East])
			printHelper.PrintPoint(Point(curLocation.getX() + 1, curLocation.getY()), 'W');

		// Update console by last location
		this->printHelper.PrintPoint(curLocation, house.getPointInfo(curLocation));

		// make the move & Update vars
		this->moveByDirection(*iterator);
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
	}
}







