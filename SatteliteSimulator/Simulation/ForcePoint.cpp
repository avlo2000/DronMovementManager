#pragma once
#include "ForcePoint.h"

namespace simulator
{
	ForcePoint::ForcePoint()
		: Point()
	{
		this->_force = Vector3d(0, 0, 0);
	};
	ForcePoint::ForcePoint(Vector3d force, double x, double y, double z)
		: Point(x, y, z)
	{
		this->_force = force;
	};
	void ForcePoint::Rotate(double time)
	{
		Point::Rotate(time);

		double angle = this->rotSpeed * time;
		
		this->_force = RotateVector(this->_force, this->axesVector, Point(this->axesPoint.x(),
			this->axesPoint.y(), this->axesPoint.z()), angle);
	}
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