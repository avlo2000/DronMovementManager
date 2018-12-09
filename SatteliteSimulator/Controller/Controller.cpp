#include "Controller.h"
#include "NeuralNetwork.h"
#include "Sample.h"


namespace controller {
		void Controller::SetSample(Sample &sample) {
			_sample = sample;
		}
		void Controller::ControlRotation(Vector3d rotSpeed) {
			_sample.AddRotSpeed(rotSpeed);
		}

		void Controller::ControlInstanceSpeed(Vector3d instSpeed) {
			_sample.AddInstSpeed(instSpeed);
		}
		Sample  Controller::GetSample() {
			return _sample;
		}
		void Controller::Generate(int rangeStart, int rangeEnd, int sampleSize) {
			vector<double> firstNeuronInput;
			srand(time(0));
			for (int i = 0; i < sampleSize; i++) {
				firstNeuronInput.push_back(rangeStart + (rand() / (RAND_MAX + 1.0) *(rangeEnd - rangeStart)));
			}
			vector<double> secondNeuronInput(firstNeuronInput);
			vector<double> thirdNeuronInput(firstNeuronInput);
			
			for (int size = firstNeuronInput.size(); 0 < size; size--) {
				Sattelite sattelite = *(this->_obj);
				int randIndex1 = rand() % size;
				int randIndex2 = rand() % size;
				int randIndex3 = rand() % size;
				sattelite.SetReactionWheelSpeed(0, firstNeuronInput.at(randIndex1));
				sattelite.SetReactionWheelSpeed(1, secondNeuronInput.at(randIndex2));
				sattelite.SetReactionWheelSpeed(2, thirdNeuronInput.at(randIndex3));
				sattelite.MoveAndRotate(1.0);
				this->ControlInstanceSpeed(Vector3d(firstNeuronInput.at(randIndex1), secondNeuronInput.at(randIndex2), thirdNeuronInput.at(randIndex3)));
				this->ControlRotation(sattelite.GetRotationSpeeds());
				firstNeuronInput.erase(firstNeuronInput.begin() + randIndex1);
				secondNeuronInput.erase(secondNeuronInput.begin() + randIndex2);
				thirdNeuronInput.erase(thirdNeuronInput.begin() + randIndex3);
			}
		}
}
