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
	contr.RegisterObject(&testSat);
	contr.Train(0,40,4,10,30,3,0.001,100,1000);
	
	system("pause");
	return 0;
}