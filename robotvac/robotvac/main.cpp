#include <iostream>
#include "SimulationPrintUtils.h"
#include "Simulation.h"
#include "House.h"
#include "ConsoleUtils.h"
using namespace std;








void print(char ** c, int len, int width)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << c[j][j];
		}
		cout << endl;
	}
}

void main()
{

	KeyboardAlgo algo;
	Simulation simulation;
	simulation.addAlgo(algo);

	bool showMainMenu = true;
	bool exit = false;

	while (showMainMenu)
	{
		SimulationPrintUtils::printInitialMenu();

		showMainMenu = false;
		exit = false;

		while (_kbhit && !exit)
		{
			int key = _getch();
			if (key == '1')
			{
				clear_screen();
				simulation.prepareSimultaion();

				// If there is any valid Houses
				HouseValidation houseValidation = simulation.isValidHouse();

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
						showMainMenu = true;
						clear_screen();
						exit = true;
					}
					else
					{
						exit = true;
						simulation.endSimulation();
						return;
					}
					
				}
				else
				{
					SimulationPrintUtils::printInvalidHouse(houseValidation);			
					exit = true;
				}
			}
			else if (key == '8')
			{
				clear_screen();
				SimulationPrintUtils::printInsruction();
			}
			else if (key = '9')
			{
				return;
			}

		}
	}
}
