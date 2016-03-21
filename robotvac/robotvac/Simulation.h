#ifndef _SIMULATION_H_
#define _SIMULATION_H_

// Includes
#include "Sensor.h"
#include "KeyboardAlgo.h"
#include "House.h"
#include "Tracker.h"

//Class forward Decleraion
class KeyboardAlgo;
class House;

class Simulation{

public:
	// Public Functions
	Simulation(){}
	
	Direction Step();
    void Init();
	void Start();

private:

	// Private Data Members
	Direction lastDir;
	KeyboardAlgo keyAlgo;
	House house;

};


#endif