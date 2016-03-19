#ifndef _TRACKER_H_
#define _TRACKER_H_

// Includes
#include "KeyboardAlgo.h"
#include "Point.h"
#include "House.h"


// Class forward decleration
class KeyboardAlgo;
class Point;



class Tracker{

public:
	bool isGameFinished();

private:

	int battery;			// Batery Left
	KeyboardAlgo algo;		// Algorithem to track
	int score;				// Score for algorithem 
	Point robotLocation;	// Robot Location
	int numOfSteps;			// Num of steps since start
	House house;


};





#endif