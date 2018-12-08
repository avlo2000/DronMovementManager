#include "Satellite.h"
#include "Simulation.h"
#include <iostream>
#include "TestSatellite.h"

using namespace simulator;
using namespace std;

int main()
{
	auto testSat = CreateSatellite();

	
	Simulation sim;
	sim.AddObject(testSat);
	sim.SetTimeStep(1);

	testSat.EnergyToReactionWheel(0, -17);
	testSat.EnergyToReactionWheel(1, 0);
	testSat.EnergyToReactionWheel(2, 0);
	
	
	sim.Simulate(1, cout);
	//testSat.EnergyToReactionWheel(0, -9);
	sim.Simulate(1, cout);
	//testSat.EnergyToReactionWheel(1, -9);
	sim.Simulate(1, cout);
	system("pause");
	return 0;
}