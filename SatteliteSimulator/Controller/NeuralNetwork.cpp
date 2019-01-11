#pragma once

#include<vector>
#include <Eigen/Geometry>
#include "NeuralNetwork.h"
#include "Sample.h"
#include <fstream>
#include <iterator>



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
	Scalar operator ""_eng(long double d) {
		// Add a cast here if the compiler still complains
		return d;
	}
	void NeuralNetwork::Train(Sample &sample, int batchSize, int epoch) {
		VerboseCallback callback;
		_net.set_callback(callback);
		_net.init(NORMALDISTRIBUTIONMEAN, STANDARDDIVIATION, RANDOMSEED);
		MatrixXd input = sample.GetRotSpeed();
		MatrixXd output = sample.GetEnergy();
		_net.fit(_opt, input, output, batchSize, epoch, RANDOMSEED);
	}
	void NeuralNetwork::Save(string fileName) {
		vector<vector<Scalar>> parameters = _net.get_parameters();
		ofstream output_file(fileName);
		ostream_iterator<Scalar> output_iterator(output_file, " ");
		for (const auto& row : parameters) {
			copy(row.cbegin(), row.cend(), output_iterator);
			output_file << endl;
		}
	}
	void NeuralNetwork::LoadParameters(string fileName) {
		vector<vector<Scalar>> parameters;
		ifstream file(fileName);
		string line;
		while (getline(file, line)) {
			stringstream linestream(line);
			string item;
			vector<Scalar> tempVec;
			while (getline(linestream, item, ' ')) {
				tempVec.push_back(stold(item));
			}
			parameters.push_back(tempVec);
		}
		_net.init(NORMALDISTRIBUTIONMEAN, STANDARDDIVIATION, RANDOMSEED);
		_net.set_parameters(parameters);
	}
	MatrixXd NeuralNetwork::Predict(MatrixXd &input) {
		MatrixXd pred = _net.predict(input);
		return pred;
	}
	
	
	
}
