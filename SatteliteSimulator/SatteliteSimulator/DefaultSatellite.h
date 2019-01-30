#pragma once
#include "Satellite.h"
#include "Simulation.h"
#include <iostream>

using namespace std;

namespace simulator {

	Satellite CreateSatellite(const string& name) {
		vector<MassPoint> mPoints;
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

		Satellite sat(name, mPoints, wheels);
		return sat;
	}
}