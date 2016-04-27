#include "House.h"
#include "Sensor.h"


House::House(const char* name, const char* gameNumber, int height, int width, int _numberOfSteps, char** house, bool isValid)
	:height(height), width(width), numberOfSteps(_numberOfSteps), isValidFile(isValid)
{
	strcpy(shortName, name);
	strcpy(longName, name);
	strcpy(this->gameNumber, gameNumber);
	curHouse = new char*[height];

	// Init copy of house
	for (int i = 0; i < height; i++)
	{
		curHouse[i] = new char[width];
		strncpy(curHouse[i], house[i], width);
	}

	this->repairHouse();
	this->initTotalDirt();
}
House::House(const House& house)
{
	strcpy(shortName, house.shortName);
	strcpy(longName, house.longName);
	strcpy(this->gameNumber, house.gameNumber);
	height = house.height;
	width = house.width;
	this->isValidFile = house.isValidFile;
	curHouse = new char*[house.height];
	this->numberOfSteps = house.numberOfSteps;

	// Init copy of house
	for (int i = 0; i < house.height; i++)
	{
		curHouse[i] = new char[width];
		strncpy(curHouse[i], house.curHouse[i], width);
	}

	this->repairHouse();
	this->initTotalDirt();
}

House::~House()
{
	if (height != 0 || width != 0)
	{
		for (int i = 0; i < height; i++)
			delete this->curHouse[i];
		delete this->curHouse;
	}
}


void House::operator=(const House& _house)
{
	strcpy(shortName, _house.shortName);
	strcpy(longName, _house.longName);
	strcpy(this->gameNumber, _house.gameNumber);
	height = _house.height;
	width = _house.width;
	this->isValidFile = _house.isValidFile;
	curHouse = new char*[_house.height];
	this->numberOfSteps = _house.numberOfSteps;

	// Init copy of house
	for (int i = 0; i < height; i++)
	{
		curHouse[i] = new char[width];
		strncpy(curHouse[i], _house.curHouse[i], width);
	}

	this->repairHouse();
	this->initTotalDirt();
}

// Sensing the House at location (x,y)
struct SensorInformation House::Sense(Point location)
{
	struct SensorInformation info;

	// Check if there is wall North
	if (this->curHouse[location.getY() - 1][location.getX()] == WALL)
		info.isWall[WallInfo::North] = true;
	else
		info.isWall[WallInfo::North] = false;


	// South
	if (this->curHouse[location.getY() + 1][location.getX()] == WALL)
		info.isWall[WallInfo::South] = true;
	else
		info.isWall[WallInfo::South] = false;

	// East
	if (this->curHouse[location.getY()][location.getX() + 1] == WALL)
		info.isWall[WallInfo::East] = true;
	else
		info.isWall[WallInfo::East] = false;

	// West
	if (this->curHouse[location.getY()][location.getX() - 1] == WALL)
		info.isWall[WallInfo::West] = true;
	else
		info.isWall[WallInfo::West] = false;

	info.dirtLevel = (curHouse[location.getY()][location.getX()] == ' ' ||
		curHouse[location.getY()][location.getX()] == DOCKING) ? 0 : curHouse[location.getY()][location.getX()] - '0';

	return info;
}

// Try to clean spot and return if success
bool House::Clean(Point p)
{
	char dirt = curHouse[p.getY()][p.getX()];
	if (dirt - '0' > 0 && dirt - '0' <= 9)
	{
		curHouse[p.getY()][p.getX()]--;
		this->totalDirt--;
		return true;
	}
	return false;
}

// Repair house and put walls at it
void House::repairHouse()
{
	// put walls on Sides
	for (int i = 0; i < this->height; i++)
	{
		this->curHouse[i][0] = WALL;
		this->curHouse[i][this->width - 1] = WALL;
	}

	// put Walls on Top & Bot
	for (int i = 0; i < this->width; i++)
	{
		this->curHouse[0][i] = WALL;
		this->curHouse[this->height - 1][i] = WALL;
	}
}

// Check if the house is clean
bool House::isHouseClean()
{
	if (this->totalDirt == 0)
		return true;

	return false;
}

// Get Docking Location
Point House::getFirstDockingLocation()
{
	// Check on every tile
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (this->curHouse[i][j] == DOCKING)
				return Point(j, i);
		}
	}

	return Point(-1, -1);
}

// Get Point location
char House::getPointInfo(Point location)
{
	return curHouse[location.getY()][location.getX()];
}

// Init total dirt amount
void House::initTotalDirt()
{
	this->totalDirt = 0;

	// Check on every tile
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (this->curHouse[i][j] - '0' > 0 && this->curHouse[i][j] - '0' <= 9)
				this->totalDirt = this->totalDirt + this->curHouse[i][j] - '0';
		}
	}
}

// If location is on docking
bool House::isDocking(Point location)
{
	return (this->getPointInfo(location) == DOCKING);
}

// Get anoumt of left dirt
int House::getTotalDirtLeft()
{
	return this->totalDirt;
}

// Check if house is valid for simulation
HouseValidation House::isValidHouse()
{
	if (!isValidFile)
		return HouseValidation::InvalidFileReading;
	if (this->width < 10 || this->width > 79)
		return HouseValidation::InvalidSize;
	if (this->height < MIN_HOUSE_LEN || this->height > MAX_HOUSE_LEN)
		return HouseValidation::InvalidSize;


	bool isFound = false;

	// Check the number of docking station
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (this->curHouse[i][j] == DOCKING)
				if (isFound)
				{
					return HouseValidation::TooMuchDociking;
				}
				else
				{
					isFound = true;
				}
		}
	}
	if (isFound)
	{
		return HouseValidation::Valid;
	}
	else
	{
		return HouseValidation::NoDocking;
	}
}