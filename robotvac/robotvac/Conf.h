#ifndef _CONF_H_
#define _CONF_H_

// enums
enum WallInfo{ North = 0, South = 1, East = 2, West = 3 };
enum class Direction { East, West, South, North, Stay };

// Structs
struct SensorInformation {
	int dirtLevel;
	bool isWall[4];
};

// House Configuraion
const int SHORT_NAME_LEN = 20;
const int LONG_NAME_LEN = 50;
const int MIN_HOUSE_LEN = 5;
const int MAX_HOUSE_LEN = 20;
const int MIN_HOUSE_WID = 10;
const int MAX_HOUSE_WID = 79;

// Game configuraion
const int MAX_STEPS = 1200;
const int MAX_STEPS_AFTER_WIN = 200;
const int BATTERY_CAPACITY = 400;
const int BATTERY_CONSUMPTION_RATE = 1;
const int BATTERY_RECHARGE_RATE = 20;


#define WINDOWS
#endif 