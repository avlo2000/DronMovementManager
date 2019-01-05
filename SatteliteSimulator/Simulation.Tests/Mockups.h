#pragma once
#include "Object.h"
#include <vector>

using namespace std;
using namespace simulator;

Object SimetricalObject() {
	vector<MassPoint> mPoints;
	vector<ForcePoint> fPoints;
	fPoints.push_back(ForcePoint(Vector3d(1, 0, 0), 1, 0, 0));
	mPoints.push_back(MassPoint(20, 1, 0, 0));
	mPoints.push_back(MassPoint(20, -1, 0, 0));
	mPoints.push_back(MassPoint(20, 0, 1, 0));
	mPoints.push_back(MassPoint(20, 0, -1, 0));
	mPoints.push_back(MassPoint(20, 0, 0, 1));
	mPoints.push_back(MassPoint(20, 0, 0, -1));

	Object obj("TestObj", mPoints, fPoints);
	return obj;
}

Object AsimetricalObject() {
	vector<MassPoint> mPoints;
	vector<ForcePoint> fPoints;
	mPoints.push_back(MassPoint(6, 1, 0, 0));
	mPoints.push_back(MassPoint(32, -1, 0, 0));
	mPoints.push_back(MassPoint(5, 0, 1, 0));
	mPoints.push_back(MassPoint(2, 0, -1, 0));
	mPoints.push_back(MassPoint(9, 0, 0, 1));
	mPoints.push_back(MassPoint(56, 0, 0, -1));

	Object obj("TestObj", mPoints, fPoints);
	return obj;
}