#include "Point.h"

class MassPoint :
	public Point
{
private:
	double _mass;
public:
	using Point::Point;
	explicit MassPoint(double mass, double x, double y, double z)
		: Point(x, y, z)
	{
		this->_mass = mass;
	};
	double GetMass();
	~MassPoint();
};

