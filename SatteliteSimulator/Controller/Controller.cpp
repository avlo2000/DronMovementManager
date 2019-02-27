#include "Controller.h"
#include <cmath>
#include "Exceptions.h"
#include <random>

namespace simulator {

	void Controller::SetSample(Sample &sample) {
		this->_sample = sample;
	}

	void Controller::ControlRotation(Vector3d rotSpeed) {
		if (this->_obj == NULL)
			throw UnregisteredObjectException();
		Vector3d previousRotationSpeed = _obj->GetRotationSpeeds();
		VectorXd  previosAndCurrentRotationSpeed;
		previosAndCurrentRotationSpeed << previousRotationSpeed, rotSpeed;
		MatrixXd rotSpeedMatrix = previosAndCurrentRotationSpeed;
		MatrixXd predictionMatrix = this->_neuralNetwork.Predict(rotSpeedMatrix);
		int numberOfWheels = _obj->GetNumOfWheels();
		for (int i = 0; i < numberOfWheels; i++) {
			_obj->EnergyToReactionWheel(i, predictionMatrix(i, 0));
		}

	}

	void Controller::Train(string path) {
		Generate(RANGESTART, RANGEEND, NUMBEROFSAMPLES);
		this->_neuralNetwork.SetHiddenLayers(NUMBEROFHIDDENLAYERS, HIDDENLAYERSLENGTH, this->_obj->GetNumOfWheels());
		this->_neuralNetwork.SetLearningRate(LEARNINGRATE);
		this->_neuralNetwork.Train(this->_sample, BATCHSIZE, EPOCH);
		this->_neuralNetwork.Save(path);
	}

	void Controller::LoadNetwork(string fileName) {
		this->_neuralNetwork.SetHiddenLayers(NUMBEROFHIDDENLAYERS, HIDDENLAYERSLENGTH, this->_obj->GetNumOfWheels());
		this->_neuralNetwork.SetLearningRate(LEARNINGRATE);
		this->_neuralNetwork.LoadParameters(fileName);
	}

	void Controller::Generate(double rangeStart, double rangeEnd, int numberOfSamples) {
		if (this->_obj == NULL)
			throw UnregisteredObjectException();

		vector<double> firstNeuronInput;
		int wheelSize = _obj->GetNumOfWheels();
		int previousAndCurentWheelSize = wheelSize * 2;
		int numberOfRanges = numberOfSamples;
		double step = (double)(rangeEnd - rangeStart) / numberOfRanges;
		for (int i = 0, currentSize = 0; i < numberOfRanges; i++) {
			int numberOfPointsInThisRange = (i == numberOfRanges - 1) ? numberOfSamples / numberOfRanges + numberOfSamples % numberOfRanges : numberOfSamples / numberOfRanges;
			for (int j = 0; j < numberOfPointsInThisRange; j++, currentSize++) {
				firstNeuronInput.push_back(rangeStart + (rand() / (RAND_MAX + 1.0) *(rangeStart + step - rangeStart)));
			}
			rangeStart += step;
		}
		vector<vector<double>> vectorMatrix;
		for (int i = 0; i < previousAndCurentWheelSize; i++) {
			vector<double> NeuronInput(firstNeuronInput);
			vectorMatrix.push_back(NeuronInput);
		}

		for (int size = firstNeuronInput.size(); 0 < size; size--) {
			Satellite sattelite = *(_obj);

			VectorXd inputVector(wheelSize);
			Vector3d previousRotationVector;
			for (int i = 0; i < previousAndCurentWheelSize; i++) {
				if (i == wheelSize) {
					previousRotationVector = sattelite.GetRotationSpeeds();
				}
				int randIndex = rand() % size;
				sattelite.EnergyToReactionWheel(i, vectorMatrix.at(i).at(randIndex));
				if (i >= wheelSize)
					inputVector(i - wheelSize) = vectorMatrix.at(i - wheelSize).at(randIndex);
				vectorMatrix.at(i).erase(vectorMatrix.at(i).begin() + randIndex);
			}

			this->_sample.AddEnergy(inputVector); //power
			Vector3d rotationVector = sattelite.GetRotationSpeeds();
			VectorXd previousAndCurrentRotation;
			previousAndCurrentRotation << previousRotationVector, rotationVector;
			VectorXd excpectedOutput = this->_sample.ConvertVector3dToXd(rotationVector);

			this->_sample.AddRotSpeed(excpectedOutput);

		}

	}

}
