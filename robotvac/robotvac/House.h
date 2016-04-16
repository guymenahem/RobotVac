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
	House(const char* name, const char* gameNumber, int height, int width, int _numberOfSteps, char** house);
	House(){}
	// Functions
	struct SensorInformation Sense(Point location);
	bool Clean(Point p);
	bool isHouseClean();
	bool isDocking(Point location);
	HouseValidation isValidHouse();
	Point getFirstDockingLocation();

	int getHeight(){ return height; }
	int getWidth(){ return width; }
	char getPointInfo(Point location);
	char* getHouseNumber(){ return gameNumber; }
	int getTotalDirtLeft();

private:
	char shortName[SHORT_NAME_LEN];
	char longName[LONG_NAME_LEN];
	char gameNumber[GAME_DIGIT_NUM];
	int height;
	int width;
	int numberOfSteps;
	unsigned int totalDirt;
	char ** curHouse;

	// Reapairing the house walls
	void repairHouse();
	void initTotalDirt();

};

#endif
