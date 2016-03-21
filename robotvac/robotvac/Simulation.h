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
	Direction Step();


private:

	// Private Data Members
	KeyboardAlgo keyAlgo;
	House house;

};


#endif