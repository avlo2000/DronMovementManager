#pragma once
#include "tiny_dnn/tiny_dnn.h"
#include "Sample.h"
#include <string>
using namespace tiny_dnn;
using namespace tiny_dnn::layers;
using namespace tiny_dnn::activation;
namespace controller {
	class NeuralNetwork {
	private:
		int _epoch;
		int _batch;
		network<sequential> _net;
	public:
		NeuralNetwork() {};
		NeuralNetwork(int newEpoch, int newBatch);
		void SetNumberOfHiddenLayers(int numberOfHiddelLayers, int hiddenLayersLength, int numberOfOutPutValue);
		int Epoch();
		int Batch();
		network<sequential> Network();
		void Train(Sample &sample);
		void SaveNetwork(string name);
		void LoadNetwork(string name);
		vec_t PredictNetwork(vec_t &input);
	};
}