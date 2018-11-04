#pragma once
#include"Point.h"
#include<iostream>
#include"Utils.h"

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

	void Point::X(double x)
	{
		this->x = x;
	}

	void Point::Y(double y)
	{
		this->y = y;
	}

	void Point::Z(double z)
	{
		this->z = z;
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
		this->axesPoint = Vector3d(axesPoint.X(), axesPoint.Y(), axesPoint.Z());
		this->rotSpeed = rotSpeed;
	}

	void Point::Move(double time)
	{
		this->x += this->instSpeed.x() * time;
		this->y += this->instSpeed.y() * time;
		this->z += this->instSpeed.z() * time;
	}

	void Point::Rotate(double time) {
		double angle = this->rotSpeed * time;

		*this = RotatePoint(*this, this->axesVector, Point(this->axesPoint.x(), 
			this->axesPoint.y(), this->axesPoint.z()), angle);
	}
	Point::~Point()
	{
	}

}