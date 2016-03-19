#ifndef _HOUSE_H_
#define _HOUSE_H_

#include "Sensor.h"
#include "Conf.h"
#include "Point.h"

// Class Forward Decleration
class Sensor;
class Point;



class House
{
public:
	char shortName[SHORT_NAME_LEN];
	char longName[LONG_NAME_LEN];
	int legnth;
	int width;
	char ** curHouse;


	SensorInformation Sense(Point location);
	char Clean(Point p);

private:

	// Reapairing the house walls
	void repairHouse();







};


#endif