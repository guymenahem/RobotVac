#ifndef _HOUSE_H_
#define _HOUSE_H_

#include "Sensor.h"
#include "Conf.h"
#include "Point.h"
#include <string.h>

// Class Forward Decleration
class Sensor;
class Point;


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
	SensorInformation Sense(Point location);
	
	bool Clean(Point p);
	bool isHouseClean();

private:

	// Reapairing the house walls
	void repairHouse();
	static Point findDockingStation(const char house[][MAX_HOUSE_WID + 1], int rows, int cols);
	
};

#endif