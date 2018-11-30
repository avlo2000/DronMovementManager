#pragma once
#include<vector>
#include <Eigen/Geometry>

using namespace Eigen;
using namespace std;

namespace SampleNamespace {
	class Sample {
	private:
		vector<Vector3d> instSpeed;
		vector<Vector3d> rotSpeed;
	public:
		Sample() {};
		~Sample() {};
		void addInstSpeed(Vector3d vec);
		void addRotSpeed(Vector3d vec);
		vector<Vector3d> getInstSpeed();
		vector<Vector3d> getRotSpeed();
	};
}