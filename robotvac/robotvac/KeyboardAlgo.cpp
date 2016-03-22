#include "KeyboardAlgo.h"
#include "Sensor.h"

void KeyboardAlgo::Move(Point& lastLoc)
{
	SensorInformation info = ptrSensor->Sense(lastLoc);
    
	// show on screen
}