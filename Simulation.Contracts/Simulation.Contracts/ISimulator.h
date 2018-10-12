#include <vector>
#include "IObject.h"

using namespace std;

class ISimulator
{
public:
	vector<IObject> objects;

	virtual void SetTimeStep(double timeStep) = 0;
	virtual void Simulate(double time) = 0;
};

