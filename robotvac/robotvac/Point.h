#ifndef _POINT_H_
#define _POINT_H_

class Point{

public:
	// Constructor
	Point(int _x = 0, int _y = 0) :x(_x), y(_y){};

	// public Getters/Setters
	int getX(){ return this->x; }
	int getY(){ return this->y; }
	void setX(int _x){ this->x = _x; }
	void setY(int _y){ this->y = _y; }
	void setPoint(int _x, int _y){ this->x = _x; this->y = _y; }

private:
	// Private Data Members
	int x;
	int y;


};



#endif _POINT_H_
