#pragma once
#include "Object.h"
#include "Utils.h"

namespace Simulator
{

	void Object::Init()
	{
		double mass = 0;
		double xSum = 0;
		double ySum = 0;
		double zSum = 0;
		this->_inertMoment = 0;

		for (auto mPoint : this->_mPoints)
		{
			mass += mPoint.GetMass();
			xSum += mPoint.GetMass() * mPoint.X();
			ySum += mPoint.GetMass() * mPoint.Y();
			zSum += mPoint.GetMass() * mPoint.Z();
		}


		this->_massCentre = MassPoint(mass, xSum / mass, ySum / mass, zSum / mass);

		for (auto mPoint : this->_mPoints)
			this->_inertMoment += mPoint.GetMass() * SqrDistance(this->_massCentre, mPoint);

	}

	pair<Vector3d, Vector3d> Object::GetForceComponents(int fPointIndex)
	{
		Vector3d axis(this->_fPoints[fPointIndex].X() - this->_massCentre.X(),
			this->_fPoints[fPointIndex].Y() - this->_massCentre.Y(), 
			this->_fPoints[fPointIndex].Z() - this->_massCentre.Z());

		Vector3d instForce = PrjVecOnVec(this->_fPoints[fPointIndex].GetForce(), axis);
		Vector3d rotateForce = _fPoints[fPointIndex].GetForce() - instForce;

		return pair<Vector3d, Vector3d>(instForce, rotateForce);
	}

	Object::Object(vector<MassPoint> mPoints, vector<ForcePoint> fPoints)
	{
		this->_fPoints = fPoints;
		this->_mPoints = mPoints;

		this->Init();
	}

	void Object::PowerToPoint(int fPointIndex, double power)
	{
		//TO DO

		this->_fPoints.at(fPointIndex).Activate();
	}

	Object::~Object()
	{
	}

}
