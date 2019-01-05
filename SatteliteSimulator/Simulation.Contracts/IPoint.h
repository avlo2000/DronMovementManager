#pragma once
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "IMovable.h"
#include "IRotatable.h"

using namespace Eigen;

namespace contracts {

	class IPoint : public IMovable, public IRotatable
	{
	public:
		virtual void Move(double time) {};
		virtual void Rotate(double time) {};
	};

}
