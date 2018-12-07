#pragma once
#include "IController.h"
#include <Eigen/Geometry>
#include "Sattelite.h"
#include "Sample.h"

using namespace contracts;
using namespace Eigen;


namespace controller {
	class Controller : public  IController<Sattelite>{
	private:
		Sample _sample;
	public:
		void ControlRotation(Vector3d rotSpeed);
		void ControlInstanceSpeed(Vector3d instSpeed);
	};
}
