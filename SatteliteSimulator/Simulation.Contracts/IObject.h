#include <vector>
#include "IPoint.h"
#include "IMovable.h"
#include "IRotatable.h"

namespace Contracts 
{

	class IObject : IMovable, IRotatable
	{
	protected:
		virtual void Move(double time) {};
		virtual void Rotate(double time) {};
	public:
		virtual void MoveAndRotate(double time)
		{
			this->Move(time);
			this->Rotate(time);
		};
	};

}