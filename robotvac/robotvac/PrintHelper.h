#ifndef _PRINTHELPER_H_
#define _PRINTHELPER_H_

#include "SimulationPrintUtils.h"
#include "House.h"

class PrintHelper
{
public:
	PrintHelper(){}
	PrintHelper(House * _ptrHouse);
	void PrintPoint(Point point, char charToPrint);

private:
	House * ptrHouse;
	Point  ptrDock;
};

#endif