#pragma once
#include "ForcePoint.h"

namespace Simulator
{

	void ForcePoint::SetForce(double force)
	{
		double corrCoef = force / GetVecLength(this->_force);
		Vector3d newForce(corrCoef * this->_force.x(), corrCoef * this->_force.y(), corrCoef * this->_force.z());
		this->_force = newForce;
	}
	Vector3d ForcePoint::GetForce()
	{
		return this->_force;
	}

	ForcePoint::~ForcePoint()
	{
	}

}