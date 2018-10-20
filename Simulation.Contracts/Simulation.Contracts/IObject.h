#include <vector>
#include "IPoint.h"

using namespace std;


class IObject
{
protected:
	IPoint _massCentre;
public:
	virtual void Move(double timeStep) {};
};

