#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "IMovable.h"
#include "IRotatable.h"

using namespace Eigen;

namespace contracts {

	class IPoint :public IRotatable
	{
	public:
		virtual void Rotate(double time) {};
	};

}
