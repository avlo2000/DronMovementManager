#pragma once
#include "tiny_dnn/tiny_dnn.h"
using namespace tiny_dnn;
using namespace tiny_dnn::layers;
using namespace tiny_dnn::activation;
class NetworkArchitecture {
private:
	int epoch;
	int batch;
	network<sequential> net;
public:
	NetworkArchitecture(int newEpoch, int newBatch) {
		epoch = newEpoch;
		batch = newBatch;
	}
	void setNumberOfHiddenLayers(int numberOfHiddelLayers, int hiddenLayersLength) {
		net << fully_connected_layer(3, hiddenLayersLength) << sigmoid_layer();
		for (int i = 0; i < numberOfHiddelLayers - 1; i++) {
			net << fully_connected_layer(hiddenLayersLength, hiddenLayersLength) << sigmoid_layer();
		}
		net << fully_connected_layer(hiddenLayersLength, 3) << sigmoid_layer();
	}
	int getEpoch() {
		return epoch;
	}
	int getBatch() {
		return batch;
	}
	network<sequential> getNetwork() {
		return net;
	}

};