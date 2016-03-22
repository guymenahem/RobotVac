#ifndef _KEYALGO_H_
#define _KEYALGO_H_

//Includes
#include "Conf.h"
#include "Point.h"

// Class forward decleration
class Sensor;

class KeyboardAlgo{

private:
	Direction lastDirection;
	Sensor* ptrSensor;
public:
	void SetSenosr(Sensor* _sensor)
	{
		ptrSensor = _sensor;
	}

	void Move(Point& lastLoc);

	Sensor* GetSensor()
	{
		return ptrSensor;
	}


};


#endif