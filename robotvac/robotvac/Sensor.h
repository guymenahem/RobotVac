#ifndef _SENSOR_H_
#define _SENSOR_H_

// Includes
#include "House.h"

// Class Forward decleration
class House;

// Structs
struct SensorInformation {
	int dirtLevel;
	bool isWall[4];
};

class Sensor{


public:

	// Public FUnctions
	SensorInformation Sense();

private:
	// Private Data Members
	House * house;


};


#endif