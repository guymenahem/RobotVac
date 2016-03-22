#include "Conf.h"
#include "Simulation.h"
#include "SimulationPrintUtils.h"


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
				



			}


		}

	} while (key != 27);
}


void Simulation::Init(KeyboardAlgo& algo)
{
	//House house1;
	Sensor sensor;
	Tracker tracker;
	keyAlgo = algo;
	algo.SetSenosr(&sensor);
	// here we would initilize all needed stuff for the simulation
	// houses,sensors and etc..

}