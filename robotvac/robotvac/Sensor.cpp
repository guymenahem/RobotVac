#include "Sensor.h"
#include "SimulationPrintUtils.h"

SensorInformation Sensor::Sense(Point location)
{
	return(house->Sense(location));
	house->printDiscoveredPoints(location);

}