#pragma once
#include "IController.h"
#include <Eigen/Geometry>
#include <Sample.h>
using namespace contracts;
using namespace Eigen;
namespace controller {
	class Controller : public  IController<Sample>{
	public:
		void ControlRotation(Vector3d rotSpeed);
		void ControlInstanceSpeed(Vector3d instSpeed);
	};
}
