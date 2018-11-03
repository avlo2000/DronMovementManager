#pragma once
#include "Point.h"
#include "Utils.h"

namespace Simulator
{

	class ForcePoint :
		public Point
	{
	private:
		Vector3d _force;
		bool _isActive;
	public:
		explicit ForcePoint()
			: Point()
		{
			this->_force = Vector3d(0, 0, 0);
			this->_isActive = false;
		};
		explicit ForcePoint(Vector3d force, double x, double y, double z)
			: Point(x, y, z)
		{
			this->_force = force;
		};
		void SetForce(double force);
		Vector3d GetForce();
		~ForcePoint();
	};

}