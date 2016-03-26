#ifndef _HOUSE_H_
#define _HOUSE_H_

#include <string.h>
//#include "Sensor.h"
#include "Conf.h"
#include "Point.h"


class House
{
public:

	//Constructor
	House(char _shortName[], char _longName[], int height, int width, char** house);
	House(){}
	// Functions
	struct SensorInformation Sense(Point location);
	bool Clean(Point p);
	bool isHouseClean();
	bool isDocking(Point location);
	Point getFirstDockingLocation();

	int getHeight(){ return height; }
	int getWidth(){ return width; }
	char getPointInfo(Point location);

private:
	char shortName[SHORT_NAME_LEN];
	char longName[LONG_NAME_LEN];
	int height;
	int width;
	unsigned int totalDirt;
	char ** curHouse;

	// Reapairing the house walls
	void repairHouse();
	void initTotalDirt();
};

#endif
