#ifndef _SENSOR_H_
#define _SENSOR_H_

// Includes
#include "House.h"
#include "Conf.h"
#include "Point.h"

// Class Forward decleration




class Sensor{


public:
	Sensor()
	{}
	Sensor(House* _house)
	{
		house = _house;
	}

	// Public Functions
	SensorInformation Sense(Point location);

private:
	// Private Data Members
	House* house;
};


#endif