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
	auto sat = CreateSatellite();

	Controller contr;
	contr.RegisterObject(&sat);
	contr.Train();
	Simulation sim;
	sim.AddObject(sat);

	sim.SetTimeStep(1);

	sat.SetWobbling(0.001);
	sim.Simulate(10, cout);

	contr.ControlRotation(Vector3d(0.2, 1, 1));
	sim.Simulate(1, cout);

	system("pause");
	return 0;
}