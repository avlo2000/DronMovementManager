#pragma once
#include "Simulation.h"
#include <omp.h>

simulator::Simulation::Simulation()
{
}

simulator::Simulation::~Simulation()
{
}

int simulator::Simulation::NumOfObjects()
{
	return this->objects.size();
}

vector<string> simulator::Simulation::Names()
{
	vector<string> names;
	for (auto obj : objects)
		names.push_back(obj->GetName());
	return names;
}

void simulator::Simulation::AddObject(Object &obj)
{
	this->objects.push_back(&obj);
}

simulator::Object* simulator::Simulation::GetObjByName(string name)
{
	for (auto obj : this->objects)
		if (obj->GetName() == name)
			return obj;
	
	return NULL;
}

void simulator::Simulation::SetTimeStep(double timeStep)
{
	this->_timeStep = timeStep;
}

void simulator::Simulation::Simulate(double time, ostream& logger)
{
	while (time - this->_timeStep > 0)
	{
		time -= this->_timeStep;
#pragma omp parallel
		{
#pragma omp for
			for (ptrdiff_t i = 0; i < this->objects.size(); i++)
				this->objects[i]->Rotate(this->_timeStep);
		}
		for (auto obj : objects)
			obj->LogInfo(logger);
	}
	if (time - this->_timeStep < 0)
	{
#pragma omp parallel
		{
#pragma omp for
			for (ptrdiff_t i = 0; i < this->objects.size(); i++)
				this->objects[i]->Rotate(this->_timeStep - time);
		}
		for (auto obj : objects)
			obj->LogInfo(logger);
	}
}
