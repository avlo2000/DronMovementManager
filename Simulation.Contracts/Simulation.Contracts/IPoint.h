#include <Eigen/Dense>

using namespace Eigen;

class IPoint
{
public:
	Vector3d instSpeed;
	double x, y, z;
	virtual void Move(double timeStep) {};
};

