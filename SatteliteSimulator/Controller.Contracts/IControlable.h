#pragma once
#include "IController.h"

namespace contracts {

	class IControlable
	{
	protected:
		IController<Object> *_controller;
		
	public:
		virtual void RegisterControl(IController<Object> *simulator) = 0;
		virtual void Control(Vector3d instSpeed, Vector3d rotSpeed) = 0;
	};

}
