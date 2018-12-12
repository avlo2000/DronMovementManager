#include"Sample.h"
namespace controller {
	vec_t Sample::Convertor(Vector3d &eigenVec) {
		vec_t inputData;
		inputData.push_back((float)eigenVec.x());
		inputData.push_back((float)eigenVec.y());
		inputData.push_back((float)eigenVec.z());
		return inputData;
	}
	void Sample::AddInstSpeed(Vector3d &vec) {
		_instSpeed.push_back(Convertor(vec));
	}
	void Sample::AddRotSpeed(Vector3d &vec) {
		_rotSpeed.push_back(Convertor(vec));
	}
	vector<vec_t> Sample::GetInstSpeed() {
		return _instSpeed;
	}
	vector<vec_t> Sample::GetRotSpeed() {
		return _rotSpeed;
	}
}