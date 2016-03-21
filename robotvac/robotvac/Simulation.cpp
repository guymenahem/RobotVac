#include "Config.h"
#include "Simulation.h"
#include  "SimulationPrintUtils.h"
#include  "House.h"

void Simulation::Start()
{
	int key = 0 ;
	SimulationPrintUtils::printInitialMenu();
	do
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 49)
			{
				// print initial console and start the robot
				char house[][MAX_COL + 1] =
				{

					//0123456789012345678
					"WWWWWWWWWWWWWWWWW",
					"W  123          W",
					"W               W",
					"W             D W",
					"WWWWWWWWWWWWWWWWW"
				};
				size_t rows = 5;
				size_t cols = 17;
				
				
				SimulationPrintUtils::printInitialHouseSimulation(house, rows,
					cols, House::findDockingStation(house, rows, cols));

			}


		}

	} while (key != 27);
}


void Simulation::Init()
{
	// this houses are here just for now

	char house[][MAX_COL + 1] =
	{

		//0123456789012345678
		"WWWWWWWWWWWWWWWWW",
		"W  123          W",
		"W               W",
		"W             D W",
		"WWWWWWWWWWWWWWWWW"


	};

	char bigHouse[][MAX_COL + 1] =
	{
		//         1         2         3         4         5         6         7        
		//01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
		"W                                           D                                  W", // 1
		"W                                                                              W", // 2
		"W                                                                              W", // 3
		"W                                                                              W", // 4
		"W                                                                              W", // 5
		"W                                                                              W", // 6
		"W                                                                              W", // 7
		"W                                                                              W", // 8
		"W                                                                              W", // 9
		"W                                                                              W", // 10
		"W                                                                              W", // 11
		"W                                                                              W", // 12
		"W                                                                              W", // 13
		"W                                                                              W", // 14
		"W                                                                              W", // 15
		"W                                                                              W", // 16
		"W                                                                              W", // 17
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 18
	};

	size_t rows = 5;
	size_t cols = 17;


	// here we would initilize all needed stuff for the simulation
	// houses,sensors and etc..

}