#pragma once
#include "Point.h"
class MassPoint :
	public Point
{
private:
	double mass;
public:
	using Point::Point;
	explicit MassPoint(double mass, double x, double y, double z)
		: Point(x, y, z)
	{
		this->mass = mass;
	};
	~MassPoint();
};

