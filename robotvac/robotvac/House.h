#ifndef _HOUSE_H_
#define _HOUSE_H_

#include "Conf.h"
#include "Point.h"
#include <string.h>

// Class Forward Decleration
class Sensor;


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
	House()
	{

	}
	House(char _shortName[], char _longName[], int len, int wid, char** house);

	// Functions
	SensorInformation Sense(Point location);
	
	bool Clean(Point p);
	bool isHouseClean();
    Point findDockingStation();
	void printDiscoveredPoints(Point& point);

private:

	// Reapairing the house walls
	void repairHouse();
	
};

#endif