#include "Sensor.h"
#include "House.h"

// Constructor for Sensor
Sensor::Sensor(House* _ptrHouse, Point* _ptrCurLocation)
{
	ptrHouse = _ptrHouse;
	ptrCurLocation = _ptrCurLocation;
}

// Sense
SensorInformation Sensor::sense()
{
	return this->ptrHouse->Sense(*(this->ptrCurLocation));
}