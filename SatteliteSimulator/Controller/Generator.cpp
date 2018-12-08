#include <vector>
#include <ctime>
#include <Eigen/Geometry>
#include <Eigen/Dense>
#include "Sattelite.h"
#include "Sample.h"
#include "Controller.h"
#include "Generator.h"

using namespace controller;
using namespace Eigen;
using namespace std;
namespace controller {
	Sample Generator::Generate(int rangeStart, int rangeEnd, int sampleSize) {
		vector<double> firstNeuronInput;
		srand(time(0));
		for (int i = 0; i < sampleSize; i++) {
			firstNeuronInput.push_back(rangeStart + (rand() / (RAND_MAX + 1.0) *(rangeEnd - rangeStart)));
		}
		vector<double> secondNeuronInput(firstNeuronInput);
		vector<double> thirdNeuronInput(firstNeuronInput);
		Controller controller;
		for (int size = firstNeuronInput.size(); 0 < size; size--) {
			Sattelite sattelite = (*_obj);
			int randIndex1 = rand() % size;
			int randIndex2 = rand() % size;
			int randIndex3 = rand() % size;
			sattelite.SetReactionWheelSpeed(0, firstNeuronInput.at(randIndex1));
			sattelite.SetReactionWheelSpeed(1, secondNeuronInput.at(randIndex2));
			sattelite.SetReactionWheelSpeed(2, thirdNeuronInput.at(randIndex3));
			sattelite.MoveAndRotate(1.0);
			controller.ControlInstanceSpeed(Vector3d(firstNeuronInput.at(randIndex1), secondNeuronInput.at(randIndex2), thirdNeuronInput.at(randIndex3)));
			controller.ControlRotation(sattelite.GetRotationSpeeds());
			firstNeuronInput.erase(firstNeuronInput.begin() + randIndex1);
			secondNeuronInput.erase(secondNeuronInput.begin() + randIndex2);
			thirdNeuronInput.erase(thirdNeuronInput.begin() + randIndex3);
		}
		return controller.GetSample();
	}
}