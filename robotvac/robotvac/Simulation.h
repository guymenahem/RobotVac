#ifndef _SIMULATION_H_
#define _SIMULATION_H_

// Includes
#include "House.h"
#include "KeyboardAlgo.h"
#include "Tracker.h"
#include "Conf.h"

//Class forward Decleraion
class House;
class KeyboardAlgo;
class Tracker;


class Simulation{

public:
	// Public Functions
	Simulation();	// C'tor
	Direction Step();
	void addAlgo(KeyboardAlgo& algo)
	{
		keyAlgo = algo;
	}
	void prepareSimultaion();
	void start();
	void endSimulation();

private:

	// Private Data Members
	KeyboardAlgo keyAlgo;
	House house;
	Tracker tracker;


	// Private Functions
	void loadHouses();
};


#endif
