#pragma once
#include"ISimulation.h"

using namespace Contracts;

namespace Simulator
{
	class Simulation :
		public ISimulation
	{
	private:
		double _timeStep;
	public:
		Simulation();
		~Simulation();

		virtual void SetTimeStep(double timeStep) override;
		virtual void Simulate(double time, ostream& logger) override;
	};

}

