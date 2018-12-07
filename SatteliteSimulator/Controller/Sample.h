#pragma once
#include<vector>
#include <Eigen/Geometry>

using namespace Eigen;
using namespace std;

namespace controller {
	class Sample {
	private:
		vector<Vector3d> _instSpeed;
		vector<Vector3d> _rotSpeed;
	public:
		Sample() {};
		~Sample() {};
		void AddInstSpeed(Vector3d &vec);
		void AddRotSpeed(Vector3d &vec);
		vector<Vector3d> GetInstSpeed();
		vector<Vector3d> GetRotSpeed();
	};
}