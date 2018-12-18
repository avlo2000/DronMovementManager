#pragma once
#include "Simulation.h"
#include <omp.h>

simulator::Simulation::Simulation()
{
}

void simulator::Simulation::AddObject(Object &obj)
{
	this->objects.push_back(&obj);
}

void simulator::Simulation::SetTimeStep(double timeStep)
{
	this->_timeStep = timeStep;
}

void simulator::Simulation::Simulate(double time, ostream& logger)
{
	while (time > 0)
	{
		time -= this->_timeStep;
#pragma omp parallel
		{
#pragma omp for
			for (ptrdiff_t i = 0; i < this->objects.size(); i++)
				this->objects[i]->MoveAndRotate(this->_timeStep);
		}
		for (auto obj : objects)
			obj->LogInfo(logger);
	}
}

simulator::Simulation::~Simulation()
{
}