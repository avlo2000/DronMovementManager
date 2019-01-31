#include "GlbState.h"

namespace simulator {

	GlbState::GlbState()
	{
	}

	void GlbState::AddObject(Object& obj)
	{
		this->SimulationInstance().AddObject(obj);
	}

	void GlbState::AddController(Controller& cntr)
	{
		const auto name = cntr.GetRegistration()->GetName();
		this->ControllersInstance().insert({name, cntr });
	}

	void GlbState::Control(Vector3d& rots, string& satName)
	{
		this->ControllersInstance()[satName].ControlRotation(rots);
	}

	void GlbState::Simulate(double time, ostream& logger)
	{
		this->SimulationInstance().Simulate(time, logger);
	}

	void GlbState::SetTimeStep(double time)
	{
		this->SimulationInstance().SetTimeStep(time);
	}


	GlbState::~GlbState()
	{
	}

}