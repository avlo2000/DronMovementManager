#pragma once
#include "IController.h"
#include <Eigen/Geometry>
#include "Sattelite.h"
#include "Sample.h"

using namespace contracts;
using namespace Eigen;
using namespace SampleNamespace;

namespace controller {
	class Controller : public  IController<Sattelite>{
	private:
		Sample sample;
	public:
		void ControlRotation(Vector3d rotSpeed);
		void ControlInstanceSpeed(Vector3d instSpeed);
	};
}
