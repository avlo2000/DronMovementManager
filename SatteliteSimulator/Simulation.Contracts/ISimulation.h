#include <vector>
#include "IObject.h"

using namespace std;

namespace contracts
{

	class ISimulation
	{
	public:
		virtual void SetTimeStep(double timeStep) = 0;
		virtual void Simulate(double time, ostream &logger) = 0;
	};

}