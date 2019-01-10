#pragma once

#include<vector>
#include <Eigen/Geometry>
#include "NeuralNetwork.h"
#include "Sample.h"


using namespace Eigen;

namespace controller {
	
	void NeuralNetwork::SetHiddenLayers(int numberOfHiddenLayers, int hiddenLayersLength, int numberOfOutputNode) {
		_net.add_layer(new FullyConnected<Identity>(3, hiddenLayersLength));
		for (int i = 0; i < numberOfHiddenLayers; i++) {
			_net.add_layer(new FullyConnected<Sigmoid>(hiddenLayersLength, hiddenLayersLength));
		}
		_net.add_layer(new FullyConnected<Identity>(hiddenLayersLength, numberOfOutputNode));
		_net.set_output(new RegressionMSE());
	}
	void NeuralNetwork::SetLearningRate(double learningRate) {
		_opt.m_lrate = learningRate;
	}
	
	void NeuralNetwork::Train(Sample &sample, int batchSize, int epoch) {
		VerboseCallback callback;
		_net.set_callback(callback);
		_net.init(0, 0.01, 40);
		MatrixXd input = sample.GetRotSpeed();
		MatrixXd output = sample.GetEnergy();
		_net.fit(_opt, input, output, batchSize, epoch, 40);
	}
	MatrixXd NeuralNetwork::Predict(MatrixXd &input) {
		MatrixXd pred = _net.predict(input);
		return pred;
	}
	
	
	
}
