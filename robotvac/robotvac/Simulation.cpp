#include "Conf.h"
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
				char house[][MAX_HOUSE_WID] =
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




	// here we would initilize all needed stuff for the simulation
	// houses,sensors and etc..

}