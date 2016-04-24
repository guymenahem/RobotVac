#include "PrintHelper.h"
#include "SimulationPrintUtils.h"


PrintHelper::PrintHelper(House * _ptrHouse)
{
	ptrHouse = _ptrHouse;
	ptrDock = ptrHouse->getFirstDockingLocation();
}


void PrintHelper::PrintPoint(Point point, char charToPrint)
{
	SimulationPrintUtils::printPointOnMovedHouse(ptrHouse->getHeight(), ptrHouse->getWidth(), point, ptrDock, charToPrint);
}