#include "Sattelite.h"
#include "Simulation.h"
#include <iostream>

using namespace simulator;
using namespace std;

int main()
{
	vector<MassPoint> mPoints;
	vector<ForcePoint> fPoints;
	vector<ReactionWheel> wheels;
	mPoints.push_back(MassPoint(1, 1, 0, 0));
	mPoints.push_back(MassPoint(1, -1, 0, 0));
	mPoints.push_back(MassPoint(1, 0, 1, 0));
	mPoints.push_back(MassPoint(1, 0, -1, 0));
	mPoints.push_back(MassPoint(1, 0, 0, 1));
	wheels.push_back(ReactionWheel(1, 0, 0, -1, Vector3d(0, 1, 0), 3));
	fPoints.push_back(ForcePoint(Vector3d(1, 1, 1), 0, 0, 0));

	Sattelite obj("MySattelite", mPoints, fPoints, wheels);
	obj.SetReactionWheelSpeed(0, 1);
	obj.PowerToPoint(0, 1, 0.1);

	Simulation sim;
	sim.AddObject(obj);
	sim.SetTimeStep(0.1);
	sim.Simulate(2, cout);

	system("pause");
	return 0;
}