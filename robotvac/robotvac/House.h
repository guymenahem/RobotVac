#ifndef _HOUSE_H_
#define _HOUSE_H_

#include <string.h>
//#include "Sensor.h"
#include "Conf.h"
#include "Point.h"


class House
{
public:
	char shortName[SHORT_NAME_LEN];
	char longName[LONG_NAME_LEN];
	int length;
	int width;
	char ** curHouse;

	//Constructor
	House(char _shortName[], char _longName[], int len, int wid, char** house);

	// Functions
	struct SensorInformation Sense(Point location);
	bool Clean(Point p);
	bool isHouseClean();
	Point getDockingLocation();

private:

	// Reapairing the house walls
	void repairHouse();
	
};

#endif