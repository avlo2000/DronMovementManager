#include "Satellite.h"
#include "Simulation.h"
#include <iostream>
#include "TestSatellite.h"
#include "../Controller/Controller.h"

using namespace simulator;
using namespace std;
using namespace controller;

int main()
{
	auto testSat = CreateSatellite();

	Controller contr;
	contr.RegisterObject(testSat);

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