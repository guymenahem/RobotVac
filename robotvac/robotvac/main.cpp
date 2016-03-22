#include "Simulation.h"
using namespace std;

int main() 
{
	KeyboardAlgo algoritem;

	Simulation simulation;
	simulation.Init(algoritem);
	simulation.Start();
}
