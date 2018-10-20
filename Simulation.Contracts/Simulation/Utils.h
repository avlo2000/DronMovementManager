#include"IPoint.h"

double SqrDistance(IPoint p1, IPoint p2)
{
	return pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0) + pow(p1.z - p2.z, 2.0);
}
