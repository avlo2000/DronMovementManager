#pragma once

#include<vector>
#include <Eigen/Geometry>
#include "NeuralNetwork.h"
#include "Sample.h"


using namespace Eigen;

namespace controller {
	
	
	void NeuralNetwork::SetHiddenLayers(int numberOfHiddenLayers, int hiddenLayersLength, int numberOfOutPutValue) {
		_net.add_layer(new FullyConnected<Identity>(3, hiddenLayersLength));
		for (int i = 0; i < numberOfHiddenLayers - 1; i++) {
			_net.add_layer(new FullyConnected<Identity>(hiddenLayersLength, hiddenLayersLength));
		}
		_net.add_layer(new FullyConnected<Identity>(hiddenLayersLength, numberOfOutPutValue));
	}
	void NeuralNetwork::SetLearningRate(double learningRate) {
		_opt.m_lrate = learningRate;
	}
	void NeuralNetwork::PrintLossOnEachEpoch() {
		VerboseCallback callback;
		_net.set_callback(callback);
	}
	void NeuralNetwork::Train(Sample &sample, int batchSize, int epoch) {
		_net.init(0, 0.01, 123);
		_net.fit(_opt, sample.GetRotSpeed(), sample.GetEnergy(), batchSize, epoch, 123);
	}
	MatrixXd NeuralNetwork::Predict(MatrixXd &input) {
		MatrixXd pred = _net.predict(input);
		return pred;
	}
	
	
	
}
