#include "Simulation.h"
#include "Tracker.h"


Simulation::Simulation()
{
	loadHouses();
}

void Simulation::prepareSimultaion()
{
	tracker.initTracker(this->house, &(this->keyAlgo));
}

void Simulation::start()
{
	while (!tracker.isGameFinished())
	{
		tracker.step();
	}
}

void Simulation::endSimulation()
{
	//delete &(tracker);
}

void Simulation::loadHouses()
{
	//char* bigHouse[24] = {
	//	//	         10        20        30        40        50        60        70       79
	//	//	01234567890123456789012345678901234567890123456789012345678901234567890123456789
	//	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
	//	"W WWWWW WWWW                                            W                      W", // 1
	//	"W D111111111                                            W                      W", // 2
	//	"W WWWWW WWWW                             W              W                      W", // 3
	//	"W                                       WW              W                      W", // 4
	//	"W                                WWWWWWWWW              W                       ", // 5
	//	"W                                                       W                       ", // 6
	//	"W                                                       W                       ", // 7
	//	"W                       WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW          ", // 8
	//	"W                                                                               ", // 9
	//	"W                                                                               ", // 10
	//	"W                                                                               ", // 11
	//	"W                                                                               ", // 12
	//	"W                                                                               ", // 13
	//	"W                                                                              W", // 14
	//	"W                                                                              W", // 15
	//	"W                                                                              W", // 16
	//	"W                                                                              W", // 17
	//	"W                                                                              W", // 18
	//	"W                                                                              W", // 19
	//	"W                                                                              W", // 20
	//	"W                                                                              W", // 21
	//	"W                                                                              W", // 22
	//	"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                 WWWWWWWWWWWWWWWWWWWWWWWWWWWW"  // 23
	//	//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
	//};

	char* bigHouse[24] = {
		//	         10        20        30        40        50        60        70       79
		//	01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
		"W                                                  W     W                     W", // 1
		"W                                                 W      W                     W", // 2
		"W                                        W        W      W                     W", // 3
		"W                                       WW        W      W                     W", // 4
		"W                               WWWWWWWWWW        W      W                      ", // 5
		"W                               W1113333D         W      W                      ", // 6
		"W                               W11123333222222222W       W                     ", // 7
		"W                       WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW          ", // 8
		"W                                                                               ", // 9
		"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                 WWWWWWWWWWWWWWWWWWWWWWWWWWWW"  // 23
		//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
	};



	house = House("ggg", "long", 11, 80, bigHouse);
}
