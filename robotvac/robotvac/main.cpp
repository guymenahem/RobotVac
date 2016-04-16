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

	KeyboardAlgo algo;
	Simulation simulation;
	simulation.addAlgo(algo);

	bool showMainMenu = false;
	bool exit = false;
	HouseValidation houseValidation = HouseValidation::InvalidSize;

	MainMenuState mainMenuState = Menus::mainMenu();



	while (!exit)
	{
		switch (mainMenuState)
		{

		case MainMenuState::Start:

			clear_screen();
			simulation.prepareSimultaion();

			// If there is any valid Houses
			houseValidation = simulation.isValidHouse();

			if (houseValidation == HouseValidation::Valid)
			{
				while (simulation.getState() != SimulationState::NotPrepared &&
					simulation.getState() != SimulationState::Finished &&
					simulation.getState() != SimulationState::GoToMainMenu)
				{
					simulation.start();

					if (simulation.getState() == SimulationState::WaitForRestart)
					{
						simulation.prepareSimultaion();
					}
				}

				if (simulation.getState() == SimulationState::GoToMainMenu)
				{
					mainMenuState = Menus::mainMenu();
				}
				if (simulation.getState() == SimulationState::Finished)
				{
					exit = true;
					simulation.endSimulation();
					return 0;
				}

			}
			// House is invalid - TODO : Move to simulation
			else
			{
				SimulationPrintUtils::printInvalidHouse(houseValidation);
				exit = true;
			}

			break;

		// Choose instruction
		case MainMenuState::Instruction:
			Menus::instructionMenu();
			mainMenuState = Menus::mainMenu();
			break;

		// Choose exit
		case MainMenuState::Exit:
			return 0;
		}
	}
	return 0;
}



//int main()
//{
//
//
//	KeyboardAlgo algo;
//	Simulation simulation;
//	simulation.addAlgo(algo);
//
//	bool showMainMenu = true;
//	bool exit = false;
//
//	while (showMainMenu)
//	{
//		SimulationPrintUtils::printInitialMenu();
//
//		showMainMenu = false;
//		exit = false;
//
//		while (_kbhit && !exit)
//		{
//			int key = _getch();
//			if (key == '1')
//			{
//				clear_screen();
//				simulation.prepareSimultaion();
//
//				// If there is any valid Houses
//				HouseValidation houseValidation = simulation.isValidHouse();
//
//				if (houseValidation == HouseValidation::Valid)
//				{
//					while (simulation.getState() != SimulationState::NotPrepared &&
//						simulation.getState() != SimulationState::Finished &&
//						simulation.getState() != SimulationState::GoToMainMenu)
//					{
//						simulation.start();
//
//						if (simulation.getState() == SimulationState::WaitForRestart)
//						{
//							simulation.prepareSimultaion();
//						}
//					}
//
//					if (simulation.getState() == SimulationState::GoToMainMenu)
//					{
//						showMainMenu = true;
//						clear_screen();
//						exit = true;
//					}
//					else
//					{
//						exit = true;
//						simulation.endSimulation();
//						return 0;
//					}
//					
//				}
//				else
//				{
//					SimulationPrintUtils::printInvalidHouse(houseValidation);			
//					exit = true;
//				}
//			}
//			else if (key == '8')
//			{
//				clear_screen();
//				SimulationPrintUtils::printInsruction();
//			}
//			else if (key = '9')
//			{
//				return 0;
//			}
//
//		}
//	}
//
//	return 0;
//}
