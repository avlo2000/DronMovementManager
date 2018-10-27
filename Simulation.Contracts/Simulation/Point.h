#pragma once
#include "IPoint.h"

using namespace Contracts;

namespace Simulator 
{

	class Point : public IPoint
	{
	protected:
		double x, y, z;
		Vector3d axesVector;
		Point *axesPoint;
	public:
		double X();
		double Y();
		double Z();
		void X(double x);
		void Y(double y);
		void Z(double z);
		explicit Point();
		explicit Point(double x, double y, double z);
		void SetInstSpeed(Vector3d speed);
		void SetRotation(Vector3d axesVector, Point axesPoint, double rotSpeed);
		void Move(double time);
		void Rotate(double time);
		~Point();
	};

}
