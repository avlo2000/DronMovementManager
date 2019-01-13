#pragma once
#include "IController.h"
#include <Eigen/Geometry>
#include "Satellite.h"
#include "Sample.h"
#include "NeuralNetwork.h"
#include "NeuralConfig.h"
#include <string>

using namespace contracts;
using namespace simulator;
using namespace Eigen;


namespace controller {
	class Controller : public  IController<Satellite>{
	private:
		Sample _sample;
		NeuralNetwork _neuralNetwork;
	public:
		Controller() {};
		~Controller() {};
		virtual void RegisterObject(Satellite *sat);
		void SetSample(Sample &sample);
		void ControlRotation(Vector3d instSpeed);
		void ControlInstanceSpeed(Vector3d instSpeed);
		void LoadNetwork(string fileName);
		void Generate(double rangeStart, double rangeEnd, int sampleSize);
		void Train();
	};
}
