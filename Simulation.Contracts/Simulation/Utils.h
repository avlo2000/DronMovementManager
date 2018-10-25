#pragma once
#include"Point.h"
#define SQR(x) x*x

namespace Simulator
{
	inline double SqrDistance(Point p1, Point p2)
	{
		return SQR(p1.X() - p2.X()) + SQR(p1.Y() - p2.Y()) + SQR(p1.Z() - p2.Z());
	}

	inline double GetVecLength(Vector3d vec)
	{
		return sqrt(SQR(vec.x()) + SQR(vec.y()) + SQR(vec.z()));
	}

	inline Vector3d PrjVecOnVec(Vector3d prjVec, Vector3d targetVec)
	{
		double prjLen = (prjVec.transpose() * targetVec).sum() / GetVecLength(targetVec);
		double corrCoef = prjLen / GetVecLength(targetVec);
		return Vector3d(corrCoef * targetVec.x(), corrCoef * targetVec.y(), corrCoef * targetVec.z());
	}
}
