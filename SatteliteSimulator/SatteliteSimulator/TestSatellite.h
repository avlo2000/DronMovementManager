#pragma once
#include "Satellite.h"
#include "Simulation.h"
#include <iostream>

using namespace simulator;
using namespace std;

Satellite CreateSatellite() {
	vector<MassPoint> mPoints;
	vector<ForcePoint> fPoints;
	vector<ReactionWheel> wheels;
	mPoints.push_back(MassPoint(20, 1, 0, 0));
	mPoints.push_back(MassPoint(20, -1, 0, 0));
	mPoints.push_back(MassPoint(20, 0, 1, 0));
	mPoints.push_back(MassPoint(20, 0, -1, 0));
	mPoints.push_back(MassPoint(20, 0, 0, 1));
	mPoints.push_back(MassPoint(20, 0, 0, -1));
	wheels.push_back(ReactionWheel(1, 0, 0, 0, Vector3d(1, 0, 0), 3));
	wheels.push_back(ReactionWheel(1, 0, 0, 0, Vector3d(0, 1, 0), 3));
	wheels.push_back(ReactionWheel(1, 0, 0, 0, Vector3d(0, 0, 1), 3));

	Satellite sat("TestSattelite", mPoints, fPoints, wheels);
	return sat;
}