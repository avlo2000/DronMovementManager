#pragma once
#include<vector>
#include <Eigen/Geometry>
#include "tiny_dnn/tiny_dnn.h"

using namespace tiny_dnn;
using namespace tiny_dnn::activation;
using namespace tiny_dnn::layers;
using namespace Eigen;
using namespace std;

namespace controller {
	class Sample {
	private:
		vector<vec_t> _instSpeed;
		vector<vec_t> _rotSpeed;
	public:
		Sample() {};
		~Sample() {};
		vec_t Convertor(Vector3d &vec);
		void AddInstSpeed(Vector3d &vec);
		void AddRotSpeed(Vector3d &vec);
		vector<vec_t> GetInstSpeed();
		vector<vec_t> GetRotSpeed();
	};
}