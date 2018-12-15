#include "Controller.h"
#include "NeuralNetwork.h"
#include "Sample.h"
#include <cmath>
class NotImplementedException : public std::logic_error{
public:
	virtual char const * what() const { return "Function not yet implemented."; }
}notImplementedException;
namespace controller {
		void Controller::SetSample(Sample &sample) {
			_sample = sample;
		}
		void Controller::ControlRotation() {
			throw notImplementedException;
		}

		void Controller::ControlInstanceSpeed(Vector3d instSpeed) {
			vec_t convertedVector = this->_sample.Convertor(instSpeed);
			Sattelite sattelite = *(this->_obj);
			vec_t predictionVector = this->_neuralNetwork.PredictNetwork(convertedVector);
			sattelite.PowerToWheel(predictionVector.at(0));
			sattelite.PowerToWheel(predictionVector.at(1));
			sattelite.PowerToWheel(predictionVector.at(2));
		}
		Sample  Controller::GetSample() {
			return _sample;
		}
		void Controller::Generate(double rangeStart, double rangeEnd, int sampleSize) {
			vector<double> firstNeuronInput;
			srand(time(0));
			int numberOfRanges = 5 * log10(sampleSize);
			double step = (double)(rangeEnd - rangeStart)/numberOfRanges;
			for (int i = 0; i < numberOfRanges; i++) {
				int numberOfPointsInThisRange = (i == numberOfRanges - 1) ? sampleSize / numberOfRanges + sampleSize % numberOfRanges : sampleSize / numberOfRanges;
				for (int j = 0; j < numberOfPointsInThisRange; j++) {
					firstNeuronInput.push_back(rangeStart + (rand() / (RAND_MAX + 1.0) *(rangeStart + step - rangeStart)));
				}
				rangeStart += step;
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
				Vector3d inputData(firstNeuronInput.at(randIndex1), secondNeuronInput.at(randIndex2), thirdNeuronInput.at(randIndex3));
				this->_sample.AddInstSpeed(inputData);
				this->_sample.AddRotSpeed(sattelite.GetRotationSpeeds());
				firstNeuronInput.erase(firstNeuronInput.begin() + randIndex1);
				secondNeuronInput.erase(secondNeuronInput.begin() + randIndex2);
				thirdNeuronInput.erase(thirdNeuronInput.begin() + randIndex3);
			}
		}
}
