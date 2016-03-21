#include "House.h"

House::House(char _shortName[], char _longName[], int len, int wid, char ** house)
	:length(len), width(wid)
{
	strcpy(shortName, _shortName);
	strcpy(longName, _longName);
	curHouse = new char*[wid];

	// Init copy of house
	for (int i = 0; i < wid; i++)
	{
		curHouse[i] = new char[len];
		strcpy(curHouse[i], house[i]);
	}

	repairHouse();
}

// Sensing the House at location (x,y)
struct SensorInformation House::Sense(Point location)
{
	struct SensorInformation info;

	// Check if there is wall North
	if (this->curHouse[location.getX()][location.getY() - 1] == WALL)
		info.isWall[WallInfo::North] = true;

	// South
	if (this->curHouse[location.getX()][location.getY() + 1] == WALL)
		info.isWall[WallInfo::South] = true;

	// East
	if (this->curHouse[location.getX() + 1][location.getY()] == WALL)
		info.isWall[WallInfo::East] = true;

	// West
	if (this->curHouse[location.getX() - 1][location.getY()] == WALL)
		info.isWall[WallInfo::East] = true;

	info.dirtLevel = curHouse[location.getX()][location.getY()];

	return info;
}

// Try to clean spot and return if success
bool House::Clean(Point p)
{
	char dirt = curHouse[p.getX()][p.getY()]--;
	return ((dirt - '0' > 0 && dirt - '0' <= 9));

}

// Repair house and put walls at it
void House::repairHouse()
{
	// put walls on Sides
	for (int i = 0; i < this->width; i++)
	{
		this->curHouse[i][0] = WALL;
		this->curHouse[i][this->length - 1] = WALL;
	}
		
	// put Walls on Top & Bot
	for (int i = 0; i < this->length; i++)
	{
		this->curHouse[0][i] = WALL;
		this->curHouse[this->width - 1][i] = WALL;
	}
}

// Check if the house is clean
bool House::isHouseClean()
{
	// Check on every tile
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->length; j++)
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
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			if (this->curHouse[i][j] == DOCKING)
				return Point(j, i);
		}
	}
}

