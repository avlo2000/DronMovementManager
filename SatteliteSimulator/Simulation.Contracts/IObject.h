#pragma once
#include <vector>
#include<iostream>
#include "IPoint.h"
#include "IRotatable.h"

using namespace std;

namespace contracts 
{

	class IObject : IRotatable
	{
	protected:
		virtual void Rotate(double time) {};
	public:
		virtual void MoveAndRotate(double time)
		{
			this->Rotate(time);
		};
	};

}