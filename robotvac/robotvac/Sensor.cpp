#include "Sensor.h"
#include "House.h"

// Constructor for Sensor
Sensor::Sensor(House * ptrHouse) : house(ptrHouse) {}

// Sense
SensorInformation Sensor::Sense(Point p)
{
	return this->house->Sense(p);
}