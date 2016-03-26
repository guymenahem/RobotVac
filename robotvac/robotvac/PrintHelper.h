#include "SimulationPrintUtils.h"
#include "House.h"

class PrintHelper
{
	public:
		PrintHelper(){}
		PrintHelper(House * _ptrHouse, Point* _ptrDock);
		void PrintPoint(Point point, char charToPrint);

	private:
		House * ptrHouse;
		Point * ptrDock;
};