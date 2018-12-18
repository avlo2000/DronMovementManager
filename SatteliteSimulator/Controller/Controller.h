#pragma once
#include "IController.h"
#include <Eigen/Geometry>
#include "Satellite.h"
#include "Sample.h"
#include "NeuralNetwork.h"

using namespace contracts;
using namespace simulator;
using namespace Eigen;


namespace controller {
	class Controller : public  IController<Satellite>{
	protected:
		Sample _sample;
		NeuralNetwork _neuralNetwork;
	public:
		Controller() {};
		~Controller() {};
		void SetSample(Sample &sample);
		Sample GetSample();
		void ControlRotation(Vector3d instSpeed);
		void ControlInstanceSpeed(Vector3d instSpeed);
		void Generate(double rangeStart, double rangeEnd, int sampleSize);
	};
}
