#include "Sensor.h"

// Constructor for Sensor
Sensor::Sensor(Tracker * ptrTracker) : tracker(ptrTracker) {}

// Sense
SensorInformation Sensor::Sense()
{
	return this->tracker->Sense();
}