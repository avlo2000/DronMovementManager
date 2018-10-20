#include "IPoint.h"

class Point :
	public IPoint
{
public:
	explicit Point();
	explicit Point(double x, double y, double z);
	void SetInstSpeed(Vector3d speed);
	void SetRotation(Vector3d centre, double rotSpeed);
	void Move(double time);
	void Rotate(double time, double x, double y, double z);
	~Point();
};

