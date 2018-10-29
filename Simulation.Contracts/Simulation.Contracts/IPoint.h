#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace Eigen;

namespace Contracts 
{

	class IPoint
	{
	public:
		Vector3d instSpeed;
		double rotSpeed; //in radians per second
		virtual void Move(double time) {};
		virtual void Rotate(double time) {};
	};

}
