#include "Tracker.h"

// Check if game is finished
bool Tracker::isGameFinished()
{
	if (battery <= 0)
		return true;
	if (this->house.isHouseClean())
		return true;
	if (this->numOfSteps < MAX_STEPS)
		return true;


	return false;
}