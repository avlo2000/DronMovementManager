#pragma once
#include<vector>
#include <Eigen/Geometry>

using namespace Eigen;
using namespace std;
class Sample {
private:
	vector<Vector3d> instSpeed;
	vector<Vector3d> rotSpeed;
};