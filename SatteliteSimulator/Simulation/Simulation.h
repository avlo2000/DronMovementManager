#pragma once
#include"ISimulation.h"
#include"Object.h"

using namespace contracts;

namespace simulator
{
	class Simulation :
		public ISimulation
	{
	private:
		double _timeStep = 0.1;
		vector<Object*> objects;

	public:
		Simulation();
		~Simulation();
		void AddObject(Object &obj);
		Object* GetObjByName(string name);
		int NumOfObjects();
		vector<string> Names();
		virtual void SetTimeStep(double timeStep) override;
		virtual void Simulate(double time, ostream& logger) override;
	};

}

