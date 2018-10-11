#include <vector>
#include "IPoint.h"

using namespace std;


class IObject
{
protected:
	IPoint _massCentre;
public:
	vector<IPoint> points;
	virtual void Move(double timeStep) {};
};

