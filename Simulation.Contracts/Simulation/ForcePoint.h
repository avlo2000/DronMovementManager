#pragma once
#include "Point.h"
class ForcePoint :
	public Point
{
private:
	Vector3d force;
public:
	using Point::Point;
	explicit ForcePoint(Vector3d force, double x, double y, double z)
		: Point(x, y, z)
	{
		this->force = force;
	};
	~ForcePoint();
};

