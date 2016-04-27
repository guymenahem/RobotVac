#ifndef _TRACKER_H_
#define _TRACKER_H_

// Includes
#include "KeyboardAlgo.h"
#include "Point.h"
#include "Sensor.h"
#include <list>
using namespace std;

// Class forward decleration
class House;

class Tracker{

public:
	bool isGameFinished();
	//Tracker(House _house, KeyboardAlgo* _algo);
	Tracker(){}
	~Tracker();
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
	list<string> convertMovesListToMovesStringList();
	void restoreHouseGame();
	void restoreHouseGame(House& _originalHouse, KeyboardAlgo* _algo);
	void showHouseSolution();
	void initSavedGameMoves(list<string> movesList);

private:
	EndReason endreason;
	bool abortGame;
	bool isInited = false;			// Is Inited
	int battery;					// Batery Left
	int score;						// Score for algorithem 
	int numOfCleared;				// Num of cleared dirt
	int numOfSteps;					// Num of steps since start
	int dirtLeftToClean;			// Num of dirt  left to clean
	int initialAmountOfDirt;		// the initial amount of dirt
	int competitionPosition=1;		// the competition position
	bool returnedToDockingOnFinish; // did return to docking station when finished
	int competitonScore = 0;		// the competition positionscore
	Point curLocation;				// Robot current location
	Point dockLocation;				// Docking location
	KeyboardAlgo* algo;				// Algorithem to track
	PrintHelper printHelper;		// Print Helper 
	House  house;					// House of tracker 
	House originalHouse;            // original house of tracker (for restore use)
	list<Direction> movesList;
	
	bool checkValidStep(Direction direction);
	void moveByDirection(Direction direction);
	void restartTracker();
	void addMoveToMovesList(const Direction& dir);
	string convertDirectionSequenceToString(Direction dir, int sequenceCount);
	void saveCurrentGame();
	void saveSolutionIfBest();
	list<Direction> convertSolutionStringListToSolutionDirectionList(list<string> solList);
	bool ShowSecondaryMenu();
};





#endif
