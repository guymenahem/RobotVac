#ifndef _SIMULATION_H_
#define _SIMULATION_H_

// Includes
#include "Sensor.h"
#include "KeyboardAlgo.h"
#include "Tracker.h"

class Simulation{

public:
	// Public Functions
	Simulation(){}
	
	Direction Step();
	void Init(KeyboardAlgo& algo);
	void Start();

private:

	// Private Data Members
	Direction lastDir;
	KeyboardAlgo keyAlgo;
	Tracker tracker;
	//House house;

};


#endif