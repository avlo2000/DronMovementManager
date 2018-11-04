#pragma once
#include "Point.h"
#include "Utils.h"

namespace Simulator
{

	class ForcePoint :
		public Point
	{
	private:
		Vector3d _force; // module of vector[Newton]
	public:
		explicit ForcePoint();
		explicit ForcePoint(Vector3d force, double x, double y, double z);
		void Rotate(double time) override;
		void SetForce(double force);
		Vector3d GetForce();
		~ForcePoint();
	};

}