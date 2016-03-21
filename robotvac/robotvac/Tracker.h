#ifndef _TRACKER_H_
#define _TRACKER_H_

// Includes
#include "House.h"
#include "KeyboardAlgo.h"
#include "Point.h"
#include "Sensor.h"


// Class forward decleration
class House;


class Tracker{

public:
	bool isGameFinished();
	struct SensorInformation Sense();


private:
	
	int battery;			// Batery Left
	int score;				// Score for algorithem 
	Point curLocation;		// Robot current location
	KeyboardAlgo algo;		// Algorithem to track
	int numOfSteps;			// Num of steps since start
	Point robotLocation;	// Robot Location
	House  house;			// House of tracker - if change to House* no problem with undefined class 'House'


};





#endif