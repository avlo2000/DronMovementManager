#include "Controller.h"
#include "NeuralNetwork.h"
#include "Sample.h"
#include <cmath>
#include "Exceptions.h"

namespace controller {
		void Controller::SetSample(Sample &sample) {
			_sample = sample;
		}
		void Controller::ControlRotation(Vector3d rotSpeed) {
			vec_t convertedVector = this->_sample.Convertor(rotSpeed);
			vec_t predictionVector = this->_neuralNetwork.PredictNetwork(convertedVector);
			_obj.EnergyToReactionWheel(predictionVector.at(0));
			_obj.EnergyToReactionWheel(predictionVector.at(1));
			_obj.EnergyToReactionWheel(predictionVector.at(2));
		}

		void Controller::ControlInstanceSpeed(Vector3d instSpeed) {
			throw notImplementedException;
		}
		Sample  Controller::GetSample() {
			return _sample;
		}
		void Controller::Generate(double rangeStart, double rangeEnd, int sampleSize) {
			vector<double> firstNeuronInput;
			int wheelSize = _obj.GetNumOfWheels();
			srand(time(0));
			int numberOfRanges = 5 * log10(sampleSize);
			double step = (double)(rangeEnd - rangeStart) / numberOfRanges;
			for (int i = 0; i < numberOfRanges; i++) {
				int numberOfPointsInThisRange = (i == numberOfRanges - 1) ? sampleSize / numberOfRanges + sampleSize % numberOfRanges : sampleSize / numberOfRanges;
				for (int j = 0; j < numberOfPointsInThisRange; j++) {
					firstNeuronInput.push_back(rangeStart + (rand() / (RAND_MAX + 1.0) *(rangeStart + step - rangeStart)));
				}
				rangeStart += step;
			}
			vector<vector<double>> vectorMatrix;
			for (int i = 0; i < wheelSize; i++) {
				vector<double> NeuronInput(firstNeuronInput);
				vectorMatrix.push_back(NeuronInput);
			}
			
			for (int size = firstNeuronInput.size(); 0 < size; size--) {
				Sattelite sattelite = *(this->_obj);
				Vector3d inputVector(wheelSize);
				for (int i = 0; i < wheelSize; i++) {
					int randIndex = rand() % size;
					sattelite.SetReactionWheelSpeed(0, vectorMatrix.at(i).at(randIndex));
					inputVector(i) = vectorMatrix.at(i).at(randIndex);
					vectorMatrix.at(i).erase(vectorMatrix.at(i).begin + randIndex);
				}
				sattelite.MoveAndRotate(1.0);
				this->_sample.AddRotSpeed(inputVector);
				this->_sample.AddInstSpeed(sattelite.GetRotationSpeeds());
			}
		}
}
