#ifndef _SENSOR_H_
#define _SENSOR_H_

// Includes
#include "Point.h"
#include "House.h"

// Structs
typedef struct SensorInformation {
	int dirtLevel;
	bool isWall[4];
};


class Sensor{


public:

	//Ctor
	Sensor(House* _ptrHouse, Point* _ptrCurLocation);

	// Public Functions
	SensorInformation sense();
	Point* getCurrentLocation()
	{
		return ptrCurLocation;
	}

private:
	// Private Data Members
	House* ptrHouse;
	Point* ptrCurLocation;
};


#endif
