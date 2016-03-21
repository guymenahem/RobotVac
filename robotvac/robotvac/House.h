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
	enum { DOCKING = 'D', WALL = 'W' };
	char shortName[SHORT_NAME_LEN];
	char longName[LONG_NAME_LEN];
	int length;
	int width;
	char ** curHouse;

	//Constructors
	House();
	House(char _shortName[], char _longName[], int len, int wid, char** house);

	// Functions
	SensorInformation Sense(Point location);
	
	bool Clean(Point p);
	bool isHouseClean();
	static Point findDockingStation(const char house[][MAX_HOUSE_WID], int rows, int cols);

private:

	// Reapairing the house walls
	void repairHouse();
	
};

#endif