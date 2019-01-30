#pragma once
#include<vector>
#include <Eigen/Geometry>


using namespace Eigen;
using namespace std;

namespace simulator {
	class Sample {
	private:
		vector<VectorXd> _energy;
		vector<VectorXd> _rotSpeed;
	public:
		Sample() {};
		~Sample() {};
		MatrixXd ConvertToMatrix(vector<VectorXd> &vec);
		void AddEnergy(VectorXd &vec);
		void AddRotSpeed(VectorXd &vec);
		VectorXd ConvertVector3dToXd(Vector3d &vec);
		MatrixXd GetEnergy();
		MatrixXd GetRotSpeed();
	};
}