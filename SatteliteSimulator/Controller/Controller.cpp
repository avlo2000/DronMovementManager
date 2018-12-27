#include "Controller.h"
#include <cmath>
#include "Exceptions.h"
#include <random>

namespace controller {
		void Controller::SetSample(Sample &sample) {
			_sample = sample;
		}
		void Controller::ControlRotation(Vector3d rotSpeed) {
			MatrixXd rotSpeedMatrix = rotSpeed;
			MatrixXd predictionMatrix = _neuralNetwork.Predict(rotSpeedMatrix);
			int numberOfWheels = _obj->GetNumOfWheels();
			for (int i = 0; i < numberOfWheels; i++) {
				_obj->EnergyToReactionWheel(i, predictionMatrix(0, i));
			}
		}

		void Controller::ControlInstanceSpeed(Vector3d instSpeed) {
			//throw NotImplementedException();
		}
		
		void Controller::Generate(double rangeStart, double rangeEnd, int sampleSize) {
			vector<double> firstNeuronInput;
			int wheelSize = _obj->GetNumOfWheels();
			int numberOfRanges = 5 * log10(sampleSize);
			double step = (double)(rangeEnd - rangeStart) / numberOfRanges;
			for (int i = 0, currentSize = 0; i < numberOfRanges; i++) {
				int numberOfPointsInThisRange = (i == numberOfRanges - 1) ? sampleSize / numberOfRanges + sampleSize % numberOfRanges : sampleSize / numberOfRanges;
				for (int j = 0; j < numberOfPointsInThisRange; j++, currentSize++) {
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
				Satellite sattelite = *(_obj);
				VectorXd inputVector(wheelSize);
				for (int i = 0; i < wheelSize; i++) {
					int randIndex = rand() % size;
					sattelite.EnergyToReactionWheel(i, vectorMatrix.at(i).at(randIndex));
					inputVector(i) = vectorMatrix.at(i).at(randIndex);
					vectorMatrix.at(i).erase(vectorMatrix.at(i).begin() + randIndex);
				}
				sattelite.MoveAndRotate(1.0);
				this->_sample.AddEnergy(inputVector); //power
				Vector3d rotationVector = sattelite.GetRotationSpeeds();
				VectorXd excpectedOutput = this->_sample.ConvertVector3dToXd(rotationVector);
				this->_sample.AddRotSpeed(excpectedOutput);
			}
		}
		
}
