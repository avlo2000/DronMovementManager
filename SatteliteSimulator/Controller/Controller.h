#pragma once
#include "IController.h"
#include <Eigen/Geometry>
#include "Satellite.h"
#include "Sample.h"
#include "NeuralNetwork.h"
#include "NeuralConfig.h"

using namespace contracts;
using namespace simulator;
using namespace Eigen;


namespace controller {
	class Controller : public  IController<Satellite>{
	private:
		Sample _sample;
		NeuralNetwork _neuralNetwork;
		void Train();
	public:
		Controller() {};
		~Controller() {};
		virtual void RegisterObject(Satellite *sat);
		void SetSample(Sample &sample);
		void ControlRotation(Vector3d instSpeed) override;
		void Generate(double rangeStart, double rangeEnd, int sampleSize);
	};
}
