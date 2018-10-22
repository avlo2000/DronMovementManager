#pragma once
#include "Point.h"

namespace Simulator
{

	class ForcePoint :
		public Point
	{
	private:
		Vector3d force;
	public:
		explicit ForcePoint()
			: Point()
		{
			this->force = Vector3d(0, 0, 0);
		};
		explicit ForcePoint(Vector3d force, double x, double y, double z)
			: Point(x, y, z)
		{
			this->force = force;
		};
		~ForcePoint();
	};

}