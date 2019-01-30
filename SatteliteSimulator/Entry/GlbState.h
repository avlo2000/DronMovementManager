#pragma once
#include "Controller.h"
#include "Simulation.h"

using namespace simulator;

namespace simulator {

	class GlbState
	{
	private:
		static vector<Controller> controllers;
		Simulation simulation;
	public:
		GlbState();
		void AddObject(Object& obj);
		//void AddController(Controller& cntr);
		void Control(Vector3d& rots, string& satName);

		GlbState(GlbState const&) = delete;
		GlbState& operator= (GlbState const&) = delete;
		~GlbState();
	};

}

