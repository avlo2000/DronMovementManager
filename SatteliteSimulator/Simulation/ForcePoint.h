#pragma once
#include "Point.h"
#include "Utils.h"

namespace simulator
{

	class ForcePoint :
		public Point
	{
	private:
		Vector3d _force; // [Newton]
	public:
		explicit ForcePoint();
		explicit ForcePoint(Vector3d force, double x, double y, double z);
		void Rotate(double time) override;
		void SetForce(double force);
		Vector3d GetForce();
		~ForcePoint();
	};

}