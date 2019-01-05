#include "Controlable.h"

namespace contracts
{

	void IControlable::RegisterControl(IController<Object> *controller, Object &obj)
	{
		this->_controller = controller;
		this->_controller->RegisterObject(obj);
	}

	void IControlable::Control(Vector3d instSpeed, Vector3d rotSpeed)
	{
		this->_controller->ControlInstanceSpeed(instSpeed);
		this->_controller->ControlRotation(rotSpeed);
	}

}
