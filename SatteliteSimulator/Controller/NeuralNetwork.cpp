#pragma once

#include<vector>
#include <Eigen/Geometry>
#include "NeuralNetwork.h"
#include "Sample.h"


using namespace Eigen;

namespace controller {
	
	void NeuralNetwork::SetHiddenLayers(int numberOfHiddenLayers, int hiddenLayersLength, int numberOfOutputNode) {
		_net.add_layer(new FullyConnected<Identity>(3, hiddenLayersLength));
		for (int i = 0; i < numberOfHiddenLayers - 1; i++) {
			_net.add_layer(new FullyConnected<Sigmoid>(hiddenLayersLength, hiddenLayersLength));
		}
		_net.add_layer(new FullyConnected<Identity>(hiddenLayersLength, numberOfOutputNode));
		_net.set_output(new RegressionMSE());
	}
	void NeuralNetwork::SetLearningRate(double learningRate) {
		_opt.m_lrate = learningRate;
	}
	void NeuralNetwork::PrintLossOnEachEpoch() {
		
	}
	void NeuralNetwork::Train(Sample &sample, int batchSize, int epoch) {
		VerboseCallback callback;
		_net.set_callback(callback);
		_net.init(0, 0.01, 40);
		MatrixXd input = sample.GetRotSpeed();
		MatrixXd output = sample.GetEnergy();
		_net.fit(_opt, input, output, batchSize, epoch, 40);
		MatrixXd trainingOutput = Predict(input);
		std::cout << "speed:\n" << input(0,0) << " " << input(1,0) << " " << input(2,0) << endl;
		std::cout << "expected energy:\n" << output(0,0) << " " << output(1, 0) << " " << output(2, 0) << endl;
		std::cout << "energy:\n" << trainingOutput(0, 0) << " " << trainingOutput(1, 0) << " " << trainingOutput(2, 0) << endl;
	}
	MatrixXd NeuralNetwork::Predict(MatrixXd &input) {
		MatrixXd pred = _net.predict(input);
		return pred;
	}
	
	
	
}
