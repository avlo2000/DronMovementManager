#include "Sattelite.h"
#include "Simulation.h"
#include <iostream>
#include "TestSattelite.h"

using namespace simulator;
using namespace std;

int main()
{
	auto testSat = CreateSattelite();

	
	Simulation sim;
	sim.AddObject(testSat);
	sim.SetTimeStep(1);

	testSat.EnergyToReactionWheel(0, 1);
	testSat.EnergyToReactionWheel(1, -1);
	testSat.EnergyToReactionWheel(2, 1);

	
	sim.Simulate(1, cout);
	testSat.EnergyToReactionWheel(1, 2);
	sim.Simulate(1, cout);

	system("pause");
	return 0;
}