#pragma once
#include"Point.h"

using namespace Contracts;

namespace Simulator
{

	double SqrDistance(Point p1, Point p2)
	{
		return pow(p1.X() - p2.X(), 2.0) + pow(p1.Y() - p2.Y(), 2.0) + pow(p1.Z() - p2.Z(), 2.0);
	}

	double SqrDistance(MassPoint p1, MassPoint p2)
	{
		return pow(p1.X() - p2.X(), 2.0) + pow(p1.Y() - p2.Z(), 2.0) + pow(p1.Z() - p2.Z(), 2.0);
	}

}
