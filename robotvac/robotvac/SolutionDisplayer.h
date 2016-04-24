#ifndef _SolutionDisplayer_H_
#define _SolutionDisplayer_H_
#include "PrintHelper.h"
#include "Conf.h"
#include "House.h"
#include <list>
#include "Sensor.h"


class SolutionDisplayer
{
	private:
		PrintHelper ptrPrintHelp;
		list<Direction> movesList;
		House  house;
		Point curLocation;
		
		
	public:
		SolutionDisplayer(House curHouse, list<Direction>& lstDir);
		void moveByDirection(Direction direction);
		void StartDisplay();
};


#endif