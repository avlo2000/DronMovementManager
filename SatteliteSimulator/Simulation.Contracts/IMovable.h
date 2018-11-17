#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace Eigen;

namespace contracts
{

	class IMovable
	{
	public:
		Vector3d instSpeed; // meters per second

		virtual void Move(double time) = 0;
	};

}