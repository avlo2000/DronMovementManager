#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace Eigen;

class IPoint
{
public:
	Vector3d instSpeed;
	Vector3d rotationCentre;
	double rotSpeed; //in radians per second
	double x, y, z;
	virtual void Move(double time) {};
	virtual void Rotate(double time, double x, double y, double z) {};
};

