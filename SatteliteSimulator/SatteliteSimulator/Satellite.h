#pragma once
#include "Object.h"
#include "ReactionWheel.h"
#include <chrono>
#include <random>

namespace simulator 
{

	class Satellite : public Object
	{
	private:
		vector<ReactionWheel> _reactionWheels;

		double _wobbling;//shows fluctuation of axes caused by external random forces  
						 //there was used normal distribution for a random value
						 //this value will show dispersion of normal distribution
		void Init();
		void Wobble();
	public:
		Satellite(string name, vector<MassPoint>&, vector<ReactionWheel>&);
		vector<double> GetWheelsEnergies();
		void EnergyToReactionWheel(int index, double work);//work - energy that the wheel receivs from engine
		void SetWobbling(double wobbling);
		void Rotate(double time) override;
		int GetNumOfWheels();
		~Satellite();
	};

}

