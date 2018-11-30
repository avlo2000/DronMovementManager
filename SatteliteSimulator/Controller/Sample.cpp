#include"Sample.h"
namespace SampleNamespace {
	void Sample::addInstSpeed(Vector3d vec) {
		instSpeed.push_back(vec);
	}
	void Sample::addRotSpeed(Vector3d vec) {
		rotSpeed.push_back(vec);
	}
	vector<Vector3d> Sample::getInstSpeed() {
		return instSpeed;
	}
	vector<Vector3d> Sample::getRotSpeed() {
		return rotSpeed;
	}
}