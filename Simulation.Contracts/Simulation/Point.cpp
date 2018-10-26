#pragma once
#include "Point.h"
#include <iostream>

namespace Simulator
{

	double Point::X()
	{
		return x;
	}

	double Point::Y()
	{
		return y;
	}

	double Point::Z()
	{
		return z;
	}

	Point::Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Point::Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Point::SetInstSpeed(Vector3d speed)
	{
		this->instSpeed = speed;
	}

	void Point::SetRotation(Vector3d axesVector, Point axesPoint, double rotSpeed)
	{
		this->axesVector = axesVector;
		*this->axesPoint = axesPoint;
		this->rotSpeed = rotSpeed;
	}

	void Point::Move(double time)
	{
		this->x = this->instSpeed.x() * time;
		this->y = this->instSpeed.y() * time;
		this->z = this->instSpeed.z() * time;
	}

	void Point::Rotate(double time) {
		double angle = this->rotSpeed * time;
		Vector4d point(this->x, this->y, this->z, 1.0);
		Affine3d A = Translation3d(this->rotationCentre) * AngleAxisd(angle, this->axesVector) * Translation3d(-this->rotationCentre);
		point = (A.matrix() * point);
		this->x = point.x();
		this->y = point.y();
		this->z = point.z();
	}


	Point::~Point()
	{
	}

}