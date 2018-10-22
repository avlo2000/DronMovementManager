#include <vector>
#include "IPoint.h"

using namespace std;
using namespace Contracts;

namespace Contracts 
{

	class IObject
	{
	public:
		virtual void Move(double timeStep) {};
	};

}