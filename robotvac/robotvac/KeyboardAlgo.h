#ifndef _KEYALGO_H_
#define _KEYALGO_H_

//Includes
#include "Conf.h"
#include "Point.h"
#include "PrintHelper.h"

// Class forward decleration
class Sensor;

class KeyboardAlgo{

public:
	KeyboardAlgo()
	{
		lastDirection = Direction::Stay;
	}
	void setSensor(Sensor* sensor);
	void setPrintHelper(PrintHelper * _ptrPrintHelp);
	Direction step();
	void printCurLocation();


private:
	Direction lastDirection;
	Sensor* ptrSensor;
	PrintHelper* ptrPrintHelp;

	Direction getDirectinoByKey(char key);
	void printSensorInfo(struct SensorInformation info, Point location);
};


#endif
