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
	//Tracker(House _house, KeyboardAlgo* _algo);
	Tracker(){}
	void step();
	void initTracker(House _house, KeyboardAlgo* _algo);
	int getNumOfClearedDirt(){ return numOfCleared; }
	int getNumOfSteps(){ return numOfSteps; }
	int getNumOfInitialDirt(){ return initialAmountOfDirt; }
	int getDidReturnToDockingStationOnFinish(){ return returnedToDockingOnFinish; }
	void setCompetitionPosition(int pos){ competitionPosition = pos; }
	int getCompetitionPosition(){ return competitionPosition; }
	int getCompetitionScore(){ return competitonScore; }
	void setCompetitionScore(int score){ competitonScore = score; }
	EndReason getEndReason(){ return endreason; }

private:
	EndReason endreason;
	bool abortGame;
	int battery;			// Batery Left
	int score;				// Score for algorithem 
	int numOfCleared;		// Num of cleared dirt
	int numOfSteps;			// Num of steps since start
	int dirtLeftToClean;    // Num of dirt  left to clean
	int initialAmountOfDirt;// the initial amount of dirt
	int competitionPosition=1;// the competition position
	bool returnedToDockingOnFinish; // did return to docking station when finished
	int competitonScore = 0;// the competition positionscore
	Point curLocation;		// Robot current location
	Point dockLocation;		// Docking location
	KeyboardAlgo* algo;		// Algorithem to track
	PrintHelper printHelper;// Print Helper 
	House  house;			// House of tracker - if change to House* no problem with undefined class 'House'

	bool checkValidStep(Direction direction);
	void moveByDirection(Direction direction);
};





#endif
