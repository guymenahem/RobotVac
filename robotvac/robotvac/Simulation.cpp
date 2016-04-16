#include "Simulation.h"
#include "Tracker.h"
#include "FilesUtils.h"


Simulation::Simulation()
{
	this->state = SimulationState::NotPrepared;
}

void Simulation::prepareSimultaion()
{
	tracker.setCompetitionPosition(1);
	this->state = SimulationState::Ready;
}

void Simulation::start()
{
	string curHouseName;
	SimulationState::Running;

	while (!this->lstHousesNames.empty())
	{
		// Get the first house
		curHouseName = this->lstHousesNames.front();
		this->lstHousesNames.pop_front();
		clear_screen();

		// Load House from file name
		this->curHouse = FilesUtils::loadHouseFromFile(curHouseName);
		
		// check if house is valid for running
		if (this->curHouse.isValidHouse() == HouseValidation::Valid)
		{
			// Set tracker for this house
			tracker.initTracker(this->curHouse, &(this->keyAlgo));

			// Until game not finished
			while (!tracker.isGameFinished())
			{
				tracker.step();
			}

			winnerNumStpes = tracker.getNumOfSteps();

			EndReason endReason = tracker.getEndReason();

			switch (endReason)
			{
			case EndReason::StepIntoWall:
				SimulationPrintUtils::printInvalidStep();
				this->state = SimulationState::Finished;
				break;

			case EndReason::MainMenu:
				this->state = SimulationState::GoToMainMenu;
				return;
				break;

			case EndReason::Restart:
				// Prepare to restart house
				this->lstHousesNames.push_front(curHouseName);
				break;

			case EndReason::UserAbort:
				this->state = SimulationState::Finished;
				return;
				break;

			case EndReason::maxStepsDone:
				break;

			case EndReason::BatteryDied:
				break;

			case EndReason::FinishClean:
			default:
				int score = calcScoreForAlgo(tracker);
				SimulationPrintUtils::printScore(score);
				break;
			}
		}
		// Invalid House
		else
		{
			SimulationPrintUtils::printInvalidHouse(this->curHouse.isValidHouse());
		}
	}
	
	this->state = SimulationState::Finished;
}

int Simulation::calcScoreForAlgo(Tracker& tracker)
{
	// initial score
	int score = 2000;

	score = score - (tracker.getCompetitionPosition() - 1) * 50;
	score = score - (tracker.getNumOfInitialDirt() - tracker.getNumOfClearedDirt()) * 3;
	score = score - (winnerNumStpes - tracker.getNumOfSteps()) * 10;
	score = score + (tracker.getDidReturnToDockingStationOnFinish() ? 50 : -200);

	tracker.setCompetitionScore(score);

	return ((score > 0) ? score : 0);
}

//void Simulation::endSimulation()
//{
//	//delete &(tracker);
//}

//void Simulation::loadHouses()
//{
////	char* bigHouse[24] = {
////		//	         10        20        30        40        50        60        70       79
////		//	01234567890123456789012345678901234567890123456789012345678901234567890123456789
////		"WWDDDDDDDDDDWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
////		"W WWWWW WWWW                                            W                     W", // 1
////		"W D111111111                                            W                     W", // 2
////		"W WWWWW WWWW                             W              W                     W", // 3
////		"W                                       WW              W                     W", // 4
////		"W                                WWWWWWWWW              W                      ", // 5
////		"W                                                       W                      ", // 6
////		"W                                                       W                      ", // 7
////		"W                       WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW         ", // 8
////		"W                                                                              ", // 9
////		"W                                                                              ", // 10
////		"W                                                                              ", // 11
////		"W                                                                              ", // 12
////		"W                                                                              ", // 13
////		"W                                                                             W", // 14
////		"W                                                                             W", // 15
////		"W                                                                             W", // 16
////		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                 WWWWWWWWWWWWWWWWWWWWWWWWWWWs"  // 17
////		//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
////	};
////
////
////
////
////	this->house = House("ggg", "long", 18, 79, bigHouse);
//
//	this->curHouse = FilesUtils::loadHouseFromFile("001.House");
//}

HouseValidation Simulation::isValidHouse()
{
	return this->curHouse.isValidHouse();
}

void Simulation::restartSimultaion()
{
	prepareSimultaion();
}

void Simulation::loadHousesByFilesNames(const list<string>& lstFiles)
{
	for each(string str in lstFiles)
	{
		this->lstHousesNames.push_back(str.data());
	}
}




















//void Simulation::start()
//{
//	SimulationState::Running;
//
//	while (!tracker.isGameFinished())
//	{
//		tracker.step();
//	}
//
//	winnerNumStpes = tracker.getNumOfSteps();
//
//	EndReason endReason = tracker.getEndReason();
//
//	switch (endReason)
//	{
//	case EndReason::StepIntoWall:
//	{
//		SimulationPrintUtils::printInvalidStep();
//		this->state = SimulationState::Finished;
//		break;
//	}
//
//	case EndReason::MainMenu:
//		this->state = SimulationState::GoToMainMenu;
//		break;
//
//	case EndReason::Restart:
//		this->state = SimulationState::WaitForRestart;
//		break;
//
//	case EndReason::UserAbort:
//		this->state = SimulationState::Finished;
//		break;
//
//	case EndReason::maxStepsDone:
//		break;
//
//	case EndReason::BatteryDied:
//		break;
//
//	case EndReason::FinishClean:
//	default:
//	{
//		int score = calcScoreForAlgo(tracker);
//		SimulationPrintUtils::printScore(score);
//		this->state = SimulationState::Finished;
//		break;
//	}
//	}
//
//}