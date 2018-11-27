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
using namespace std;

void train(Sample sample) {
	NetworkArchitecture networkArchitecture(10000,1);
	networkArchitecture.setNumberOfHiddenLayers(2,6);
	network<sequential> net = networkArchitecture.getNetwork();
	adagrad optimizer;
	net.fit<mse>(optimizer, sample.getInstSpeed(), sample.getRotSpeed(), networkArchitecture.getBatch(), networkArchitecture.getEpoch());
	net.save("network");
}