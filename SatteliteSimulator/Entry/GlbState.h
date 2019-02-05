#pragma once
#include "Controller.h"
#include "Simulation.h"
#include <map>

using namespace simulator;

namespace simulator {

	//Singleton wrapper for SimulationInstance and ControllersInstance of its objects
	class GlbState
	{
	private:
		static map<string, Controller*>& ControllersInstance()
		{
			static map<string, Controller*> contrs;
			return contrs;
		};
		static Simulation& SimulationInstance()
		{
			static Simulation sim;
			return sim;
		};
	public:
		GlbState();
		void AddObject(Object& obj);
		void AddController(Controller* cntr);
		void Control(Vector3d& rots, string& satName);
		void Simulate(double time, ostream& logger);
		void SetTimeStep(double time);

		GlbState(GlbState const&) = delete;
		GlbState& operator= (GlbState const&) = delete;
		~GlbState();
	};

}

