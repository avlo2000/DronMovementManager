#include"IPoint.h"

class Point : IPoint
{
public:
	explicit Point();
	explicit Point(double x, double y, double z);
	void SetInstSpeed(Vector3d speed);
	void SetRotation(Vector3d centre, double rotSpeed);
	virtual void Move(double time);
	virtual void Rotate(double time);
	~Point();
};

