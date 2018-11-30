#include "tiny_dnn/tiny_dnn.h"
#include<vector>
#include <Eigen/Geometry>
#include <iostream>
#include "NetworkArchitecture.h"
#include "Sample.h"

using namespace tiny_dnn;
using namespace tiny_dnn::layers;
using namespace tiny_dnn::activation;
using namespace Eigen;
using namespace SampleNamespace;

namespace neuralNetwork {
	NetworkArchitecture::NetworkArchitecture(int newEpoch, int newBatch) {
		epoch = newEpoch;
		batch = newBatch;
	}
	int NetworkArchitecture::Batch() {
		return batch;
	}
	int NetworkArchitecture::Epoch() {
		return epoch;
	}
	network<sequential> NetworkArchitecture::Network() {
		return net;
	}
	void NetworkArchitecture::setNumberOfHiddenLayers(int numberOfHiddelLayers, int hiddenLayersLength) {
		net << fully_connected_layer(3, hiddenLayersLength) << sigmoid_layer();
		for (int i = 0; i < numberOfHiddelLayers - 1; i++) {
			net << fully_connected_layer(hiddenLayersLength, hiddenLayersLength) << sigmoid_layer();
		}
		net << fully_connected_layer(hiddenLayersLength, 3) << sigmoid_layer();
	}
	void NetworkArchitecture::train(Sample sample) {
		adagrad optimizer;
		net.fit<mse>(optimizer, sample.getInstSpeed(), sample.getRotSpeed(), Batch(), Epoch());
		net.save("network");
	}
}
