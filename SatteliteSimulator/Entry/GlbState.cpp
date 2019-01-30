#include "GlbState.h"

namespace simulator {

	GlbState::GlbState()
	{
	}

	void GlbState::AddObject(Object& obj)
	{
		this->simulation.AddObject(obj);
	}

	//void GlbState::AddController(Controller& cntr)
	//{
	//	this->controllers.push_back(cntr);
	//}

	//void GlbState::Control(Vector3d& rots, string& satName)
	//{
	//	Object* obj = this->simulation.GetObjByName(satName);
	//	for (auto cntr : this->controllers)
	//		if (cntr.GetRegistration() == obj)
	//			cntr.ControlRotation(rots);
	//}


	GlbState::~GlbState()
	{
	}

}