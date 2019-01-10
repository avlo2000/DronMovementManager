#pragma once
#include "IPoint.h"

using namespace contracts;

namespace simulator 
{

	class Point : public IPoint
	{
	protected:
		double x, y, z;
	public:
		
		double X();
		double Y();
		double Z();
		void X(double x);
		void Y(double y);
		void Z(double z);
		explicit Point();
		explicit Point(double x, double y, double z);
		void SetRotation(Vector3d axesVector, Point axesPoint, double rotSpeed);	
		void Rotate(double time);
		~Point();
	};

}
