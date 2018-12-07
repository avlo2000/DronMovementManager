#include "Controller.h"
#include "NeuralNetwork.h"
#include "Sample.h"


namespace controller {
	  
		void Controller::ControlRotation(Vector3d rotSpeed) {
			_sample.AddRotSpeed(rotSpeed);
		}

		void Controller::ControlInstanceSpeed(Vector3d instSpeed) {
			_sample.AddInstSpeed(instSpeed);
		}
		
}
