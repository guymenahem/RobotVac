#ifndef _SENSOR_H_
#define _SENSOR_H_

// Includes
#include "House.h"

// Class Forward decleration
class House;
enum WallInfo {North = 0, South = 1, East = 2, West = 3};

// Structs
struct SensorInformation {
	int dirtLevel;
	bool isWall[4];
};


class Sensor{


public:
	// Public Functions
	SensorInformation Sense();

private:
	// Private Data Members
	House * house;
};


#endif