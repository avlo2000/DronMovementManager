#include "Point.h"

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
	instSpeed = speed;
}

void Point::SetRotation(Vector3d centre, double rotSpeed)
{
	this->rotationCentre = centre;
	this->rotSpeed = rotSpeed;
}

void Point::Move(double time)
{
	x = instSpeed.x * time;
	y = instSpeed.y * time;
	z = instSpeed.z * time;
}

void Point::Rotate(double time)
{
	double angle = this->rotSpeed * time;

	//TO DO
}


Point::~Point()
{
}
