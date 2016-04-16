#ifndef _CONF_H_
#define _CONF_H_
#include <string>

using namespace std;


// House Configuraion
const int SHORT_NAME_LEN = 20;
const int LONG_NAME_LEN = 50;
const int MIN_HOUSE_LEN = 5;
const int MAX_HOUSE_LEN = 20;
const int MIN_HOUSE_WID = 10;
const int MAX_HOUSE_WID = 79;
const int GAME_DIGIT_NUM = 4;

// Game configuraion
const int MAX_STEPS = 1500;
const int MAX_STEPS_AFTER_WIN = 200;
const int BATTERY_CAPACITY = 400;
const int BATTERY_CONSUMPTION_RATE = 1;
const int BATTERY_RECHARGE_RATE = 20;
const string EMPTY_LINE = "                                                                                 ";
const int SLEEP_TIME = 500;

// Enums
enum class Direction { North = 0, South = 1, East = 2, West = 3, Stay };
enum WallInfo { North = 0, South = 1, East = 2, West = 3 };
enum { DOCKING = 'D', WALL = 'W' };
enum EndReason{ StepIntoWall, FinishClean, BatteryDied, maxStepsDone, Restart, UserAbort, MainMenu };
enum SimulationState{NotPrepared, Ready, Running, Finished, WaitForRestart,GoToMainMenu};
enum HouseValidation{ Valid, InvalidSize, TooMuchDociking, NoDocking };


#define WINDOWS

#endif 
