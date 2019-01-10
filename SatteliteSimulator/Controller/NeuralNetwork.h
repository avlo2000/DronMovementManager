#pragma once

#include "Sample.h"
#include <string>
#include <MiniDNN.h>

using namespace MiniDNN;
namespace controller {
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
		MatrixXd Predict(MatrixXd &input);
	};
}