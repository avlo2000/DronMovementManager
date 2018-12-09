#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace Eigen;

namespace contracts
{

	class IMovable
	{
	protected:
		Vector3d instSpeed; // meters per second
	public:
		virtual void Move(double time) = 0;
	};

}