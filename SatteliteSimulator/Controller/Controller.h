#pragma once
#include "IController.h"
#include <Eigen/Geometry>
#include "Sattelite.h"
#include "Sample.h"

using namespace contracts;
using namespace Eigen;


namespace controller {
	class Controller : public  IController<Sattelite>{
	protected:
		Sample _sample;
	public:
		Controller() {};
		~Controller() {};
		void SetSample(Sample &sample);
		Sample GetSample();
		void ControlRotation(Vector3d rotSpeed);
		void ControlInstanceSpeed(Vector3d instSpeed);
	};
}
