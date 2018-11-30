#pragma once
#include "tiny_dnn/tiny_dnn.h"
#include "Sample.h"
using namespace tiny_dnn;
using namespace tiny_dnn::layers;
using namespace tiny_dnn::activation;
namespace neuralNetwork{
	class NetworkArchitecture {
	private:
		int epoch;
		int batch;
		network<sequential> net;
	public:
		NetworkArchitecture() {};
		NetworkArchitecture(int newEpoch, int newBatch);
		void setNumberOfHiddenLayers(int numberOfHiddelLayers, int hiddenLayersLength);
		int Epoch();
		int Batch();
		network<sequential> Network();
		void train(Sample sample);
	};
}