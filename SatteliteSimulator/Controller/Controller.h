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
		Controller(double rangeStart, double rangeEnd, int numberOfSamples, int numberOfHiddenLayers, int hiddenLayersLength, int numberOfOutputNode, double learningRate, int batchSize, int epoch) {
			Generate(rangeStart, rangeEnd, numberOfSamples);
			this->_neuralNetwork.SetHiddenLayers(numberOfHiddenLayers, hiddenLayersLength, numberOfOutputNode);
			this->_neuralNetwork.SetLearningRate(learningRate);
			this->_neuralNetwork.PrintLossOnEachEpoch();
			this->_neuralNetwork.Train(this->_sample, batchSize, epoch);
		}
		~Controller() {};
		void SetSample(Sample &sample);
		void ControlRotation(Vector3d instSpeed);
		void ControlInstanceSpeed(Vector3d instSpeed);
		void Generate(double rangeStart, double rangeEnd, int sampleSize);
	};
}
