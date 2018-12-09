#include "tiny_dnn/tiny_dnn.h"
#include<vector>
#include <Eigen/Geometry>
#include <iostream>
#include "NeuralNetwork.h"
#include "Sample.h"

using namespace tiny_dnn;
using namespace tiny_dnn::layers;
using namespace tiny_dnn::activation;
using namespace Eigen;

namespace controller {
	NeuralNetwork::NeuralNetwork(int newEpoch, int newBatch) {
		_epoch = newEpoch;
		_batch = newBatch;
	}
	int NeuralNetwork::Batch() {
		return _batch;
	}
	int NeuralNetwork::Epoch() {
		return _epoch;
	}
	network<sequential> NeuralNetwork::Network() {
		return _net;
	}
	void NeuralNetwork::SetNumberOfHiddenLayers(int numberOfHiddenLayers, int hiddenLayersLength, int numberOfOutPutValue) {
		_net << fully_connected_layer(3, hiddenLayersLength) << sigmoid_layer();
		for (int i = 0; i < numberOfHiddenLayers - 1; i++) {
			_net << fully_connected_layer(hiddenLayersLength, hiddenLayersLength) << sigmoid_layer();
		}
		_net << fully_connected_layer(hiddenLayersLength, numberOfOutPutValue) << sigmoid_layer();
	}
	void NeuralNetwork::Train(Sample sample) {
		adagrad optimizer;
		_net.fit<mse>(optimizer, sample.GetInstSpeed(), sample.GetRotSpeed(), Batch(), Epoch());
		_net.save("network");
	}
}
