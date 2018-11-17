#pragma once
#include "IController.h"

namespace contracts {

	class Controlable
	{
	private:
		IController<Object> *_controller;
		
	public:
		void RegisterControle(IController<Object> *controller, Object &obj);
		void Controle(Vector3d instSpeed, Vector3d rotSpeed);
	};

}
