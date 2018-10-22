#pragma once
#include "IPoint.h"

using namespace Contracts;

namespace Simulator 
{

	class Point :
		public Contracts::IPoint
	{
	protected:
		double x, y, z;
	public:
		double X();
		double Y();
		double Z();
		explicit Point();
		explicit Point(double x, double y, double z);
		void SetInstSpeed(Vector3d speed);
		void SetRotation(Vector3d centre, double rotSpeed);
		void Move(double time);
		void Rotate(double time, double x, double y, double z);
		~Point();
	};

}
