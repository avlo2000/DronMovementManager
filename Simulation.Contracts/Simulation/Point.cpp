#include "Point.h"
#include <iostream>

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

void Point::SetRotation(Vector3d centre, double rotSpeed)
{
	this->rotationCentre = centre;
	this->rotSpeed = rotSpeed;
}

void Point::Move(double time)
{
	this->x = this->instSpeed.x() * time;
	this->y = this->instSpeed.y() * time;
	this->z = this->instSpeed.z() * time;
}

void Point::Rotate(double time, double x, double y, double z) {
	Vector3d rotAxis(x - this->x, y - this->y, z - this->z);
	double angle = this->rotSpeed * time;
	Vector4d vPoint(this->x, this->y, this->z, 0.0);
	Affine3d A = Translation3d(this->rotationCentre) * AngleAxisd(angle, rotAxis) * Translation3d(-this->rotationCentre);
	vPoint = (A.matrix() * vPoint);
	this->x = vPoint.x();
	this->y = vPoint.y();
	this->z = vPoint.z();
}


Point::~Point()
{
}
