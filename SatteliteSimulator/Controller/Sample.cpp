#include"Sample.h"
namespace controller {
	void Sample::AddInstSpeed(Vector3d &vec) {
		_instSpeed.push_back(vec);
	}
	void Sample::AddRotSpeed(Vector3d &vec) {
		_rotSpeed.push_back(vec);
	}
	vector<Vector3d> Sample::GetInstSpeed() {
		return _instSpeed;
	}
	vector<Vector3d> Sample::GetRotSpeed() {
		return _rotSpeed;
	}
}