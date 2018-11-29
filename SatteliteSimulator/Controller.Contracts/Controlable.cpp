#include "Controlable.h"

namespace contracts
{

	void Controlable::RegisterControle(IController<Object> *controller, Object &obj)
	{
		this->_controller = controller;
		this->_controller->RegisterObject(obj);
	}

	void Controlable::Controle(Vector3d instSpeed, Vector3d rotSpeed)
	{
		this->_controller->ControlInstanceSpeed(instSpeed);
		this->_controller->ControlRotation(rotSpeed);
	}

}
