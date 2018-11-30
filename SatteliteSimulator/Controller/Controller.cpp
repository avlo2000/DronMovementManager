#include "Controller.h"
#include "NetworkArchitecture.h"
#include "Sample.h"
using namespace SampleNamespace;
using namespace neuralNetwork;


namespace controller {
	  
		void Controller::ControlRotation(Vector3d rotSpeed) {
			sample.addRotSpeed(rotSpeed);
		}

		void Controller::ControlInstanceSpeed(Vector3d instSpeed) {
			sample.addRotSpeed(instSpeed);
		}
		
}
