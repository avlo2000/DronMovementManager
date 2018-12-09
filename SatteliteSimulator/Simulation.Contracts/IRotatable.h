#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace Eigen;

namespace contracts
{

	class IRotatable
	{
	protected:
		double rotSpeed; //in radians per second
		Vector3d axesVector;
		Vector3d axesPoint;
	public:
		virtual void Rotate(double time) = 0;
	};

}