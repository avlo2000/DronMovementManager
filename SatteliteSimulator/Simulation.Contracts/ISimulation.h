#include <vector>
#include "IObject.h"

using namespace std;

namespace Contracts
{

	class ISimulation
	{
	public:
		vector<IObject> objects;

		virtual void SetTimeStep(double timeStep) = 0;
		virtual void Simulate(double time) = 0;
	};

}