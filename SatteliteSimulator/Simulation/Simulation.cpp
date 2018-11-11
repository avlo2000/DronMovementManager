#pragma once
#include "Simulation.h"
#include <omp.h>

Simulator::Simulation::Simulation()
{
}

Simulator::Simulation::~Simulation()
{
}

void Simulator::Simulation::SetTimeStep(double timeStep)
{
	this->_timeStep = timeStep;
}

void Simulator::Simulation::Simulate(double time, ostream& logger)
{
	while (time > 0)
	{
		time -= this->_timeStep;
#pragma omp parallel
		{
#pragma omp for
			for (ptrdiff_t i = 0; i < this->objects.size(); i++)
				objects[i].MoveAndRotate(this->_timeStep);
		}
		for (auto obj : objects)
			obj.LogInfo(logger);
	}
}
