#include "tiny_dnn/tiny_dnn.h"
#include<vector>
#include <Eigen/Geometry>
#include <iostream>

using namespace tiny_dnn;
using namespace tiny_dnn::layers;
using namespace tiny_dnn::activation;
using namespace Eigen;
using namespace std;

void train(vector<Vector3d> instSpeed, vector<Vector3d> rotSpeed) {
	network<sequential> net;
	net << fully_connected_layer(3, 6) << sigmoid_layer()
		<< fully_connected_layer(6, 6) << sigmoid_layer()
		<< fully_connected_layer(6, 3) << sigmoid_layer();
	adagrad optimizer;
	int epochs = 10000;
	int batch = 1;
	vector<Vector3d> trainInput = instSpeed;
	vector<Vector3d> expectedOutput = rotSpeed;
	net.fit<mse>(optimizer, trainInput, expectedOutput, batch, epochs);
	net.save("network");
}