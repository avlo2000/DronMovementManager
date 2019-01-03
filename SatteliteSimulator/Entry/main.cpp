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
	auto sat = CreateSatellite();
	Controller contr;
	contr.RegisterObject(&testSat);
	contr.Train(0,40,4,10,30,3,0.001,100,10);
	Simulation sim;
	sim.AddObject(sat);
	sim.AddObject(testSat);

	sim.SetTimeStep(1);

	testSat.EnergyToReactionWheel(0, 2);
	sim.Simulate(1, cout);

	contr.ControlRotation(Vector3d(0.2, 0, 0));
	sim.Simulate(1, cout);
	system("pause");
	return 0;
}