#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "IRotatable.h"

using namespace Eigen;

namespace contracts {

	class IPoint :public IRotatable
	{
	public:
		virtual void Rotate(double time) {};
	};

}
