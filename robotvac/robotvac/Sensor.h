#ifndef _SENSOR_H_
#define _SENSOR_H_

// Includes
#include "Point.h"
#include "Tracker.h"

// Class Forward decleration
class Tracker;



class Sensor{


public:

	// Public Functions
	SensorInformation Sense();
	Sensor(Tracker * ptrTracker);

private:
	// Private Data Members
	Tracker * tracker;
};


#endif