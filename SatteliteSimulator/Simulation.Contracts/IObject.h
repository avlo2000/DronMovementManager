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
	public:
		virtual void Rotate(double time){};
	};

}