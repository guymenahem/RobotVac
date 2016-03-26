#include "PrintHelper.h"
#include "SimulationPrintUtils.h"


PrintHelper::PrintHelper(House * _ptrHouse, Point * _ptrDock)
{
	ptrHouse = _ptrHouse;
	ptrDock = _ptrDock;
}


void PrintHelper::PrintPoint(Point point, char charToPrint)
{
	SimulationPrintUtils::printPointOnMovedHouse(ptrHouse->getHeight(), ptrHouse->getWidth(), point, *ptrDock, charToPrint);
}