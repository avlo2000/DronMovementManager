#pragma once
#include "Sattelite.h"
#include "Simulation.h"
#include <iostream>

using namespace simulator;
using namespace std;

Sattelite CreateSattelite() {
	vector<MassPoint> mPoints;
	vector<ForcePoint> fPoints;
	vector<ReactionWheel> wheels;
	mPoints.push_back(MassPoint(1, 1, 0, 0));
	mPoints.push_back(MassPoint(1, -1, 0, 0));
	mPoints.push_back(MassPoint(1, 0, 1, 0));
	mPoints.push_back(MassPoint(1, 0, -1, 0));
	mPoints.push_back(MassPoint(1, 0, 0, 1));
	wheels.push_back(ReactionWheel(1, 0, 0, -1, Vector3d(1, 0, 0), 3));
	wheels.push_back(ReactionWheel(1, 0, 0, -1, Vector3d(0, 1, 0), 3));
	wheels.push_back(ReactionWheel(1, 0, 0, -1, Vector3d(0, 0, 1), 3));

	Sattelite sat("TestSattelite", mPoints, fPoints, wheels);
	return sat;
}
