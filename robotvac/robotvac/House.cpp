#include "House.h"
#include "Sensor.h"

House::House(char _shortName[], char _longName[], int height, int width, char ** house)
	:height(height), width(width)
{
	strcpy(shortName, _shortName);
	strcpy(longName, _longName);
	curHouse = new char*[height];

	// Init copy of house
	for (int i = 0; i < height; i++)
	{
		curHouse[i] = new char[width];
		strcpy(curHouse[i], house[i]);
	}

	repairHouse();
}

// Sensing the House at location (x,y)
struct SensorInformation House::Sense(Point location)
{
	struct SensorInformation info;

	// Check if there is wall North
	if (this->curHouse[location.getY() - 1][location.getX()] == WALL)
		info.isWall[WallInfo::North] = true;

	// South
	if (this->curHouse[location.getY() + 1][location.getX()] == WALL)
		info.isWall[WallInfo::South] = true;

	// East
	if (this->curHouse[location.getY()][location.getX() + 1] == WALL)
		info.isWall[WallInfo::East] = true;

	// West
	if (this->curHouse[location.getY()][location.getX() -1] == WALL)
		info.isWall[WallInfo::West] = true;

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
	// Check on every tile
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (this->curHouse[i][j]-'0' > 0 && this->curHouse[i][j]-'0' <= 9)
				return false;
		}
	}

	return true;
}

// Get Docking Location
Point House::getDockingLocation()
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
}

// Get Point location
char House::getPointInfo(Point location)
{
	return curHouse[location.getY()][location.getX()];
}

