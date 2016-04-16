#include <iostream>
#include "SimulationPrintUtils.h"
#include "Simulation.h"
#include "House.h"
#include "ConsoleUtils.h"
#include "PrintHelper.h"
#include "FilesUtils.h"
#include "Menus.h"
using namespace std;

int main()
{
	bool exit = false;
	HouseValidation houseValidation = HouseValidation::InvalidSize;

	KeyboardAlgo algo;
	Simulation simulation;
	simulation.addAlgo(algo);




	while (!exit)
	{
		MainMenuState mainMenuState = Menus::mainMenu();

		switch (mainMenuState)
		{

		case MainMenuState::Start:
			// Start Simulation for all houses
			clear_screen();
			simulation.loadHousesByFilesNames(FilesUtils::getHousesListInFolder());
			simulation.start();
			break;

		case MainMenuState::StartFromHouse:

			simulation.loadHousesByFilesNames(Menus::selectHouseToStart());
			simulation.start();
			break;

		// Choose instruction
		case MainMenuState::Instruction:
			Menus::instructionMenu();
			mainMenuState = Menus::mainMenu();
			break;

		// Choose exit
		case MainMenuState::Exit:
			exit = true;;
		}

		if (simulation.getState() == SimulationState::Finished)
		{
			exit = true;
		}
	}
	return 0;
}


//int main()
//{
//	bool exit = false;
//	HouseValidation houseValidation = HouseValidation::InvalidSize;
//
//	KeyboardAlgo algo;
//	Simulation simulation;
//	simulation.addAlgo(algo);
//
//
//	MainMenuState mainMenuState = Menus::mainMenu();
//
//
//
//	while (!exit)
//	{
//		switch (mainMenuState)
//		{
//
//		case MainMenuState::Start:
//
//			clear_screen();
//			simulation.prepareSimultaion();
//
//			// If there is any valid Houses
//			houseValidation = simulation.isValidHouse();
//
//			if (houseValidation == HouseValidation::Valid)
//			{
//				while (simulation.getState() != SimulationState::NotPrepared &&
//					simulation.getState() != SimulationState::Finished &&
//					simulation.getState() != SimulationState::GoToMainMenu)
//				{
//					simulation.start();
//
//					if (simulation.getState() == SimulationState::WaitForRestart)
//					{
//						simulation.prepareSimultaion();
//					}
//				}
//
//				if (simulation.getState() == SimulationState::GoToMainMenu)
//				{
//					mainMenuState = Menus::mainMenu();
//				}
//				if (simulation.getState() == SimulationState::Finished)
//				{
//					exit = true;
//					simulation.endSimulation();
//					return 0;
//				}
//
//			}
//			// House is invalid - TODO : Move to simulation
//			else
//			{
//				SimulationPrintUtils::printInvalidHouse(houseValidation);
//				exit = true;
//			}
//
//			break;
//
//			// Choose instruction
//		case MainMenuState::Instruction:
//			Menus::instructionMenu();
//			mainMenuState = Menus::mainMenu();
//			break;
//
//			// Choose exit
//		case MainMenuState::Exit:
//			return 0;
//		}
//	}
//	return 0;
//}