#pragma once

#include "Sample.h"
#include <string>
#include <MiniDNN.h>
#include "NeuralConfig.h"

using namespace MiniDNN;
namespace simulator {
	class NeuralNetwork {
	private:
		Network _net;
		RMSProp _opt;
	
	public:
		NeuralNetwork() {};
		~NeuralNetwork() {};
		void SetHiddenLayers(int numberOfHiddelLayers, int hiddenLayersLength, int numberOfOutputNode);
		void SetLearningRate(double learningRate);
		void Train(Sample &sample, int batchSize, int epoch);
		void Save(string fileName);
		void LoadParameters(string fileName);
		MatrixXd Predict(MatrixXd &input);
	};
}