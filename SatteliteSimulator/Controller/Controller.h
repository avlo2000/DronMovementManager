#pragma once
#include "IController.h"
#include <Eigen/Geometry>
#include "Satellite.h"
#include "Sample.h"
#include "NeuralNetwork.h"
#include "NeuralConfig.h"
#include <string>

using namespace contracts;
using namespace Eigen;


namespace simulator {

	class Controller : public  IController<Satellite>{
	private:
		Sample _sample;
		NeuralNetwork _neuralNetwork;
	public:
		Controller() {};
		~Controller() {};
		void SetSample(Sample &sample);
		void ControlRotation(Vector3d rotSpeed);
		void LoadNetwork(string fileName);
		void Generate(double rangeStart, double rangeEnd, int sampleSize);
		void Train();
	};
}
