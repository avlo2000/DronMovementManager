#pragma once
#include "Object.h"
#include "ReactionWheel.h"
#include "Controlable.h"

namespace simulator 
{

	class Sattelite : Controlable, public Object
	{
	private:
		vector<ReactionWheel> _reactionWheels;
		void Init();
	public:
		Sattelite(string name, vector<MassPoint>&, vector<ForcePoint>& , vector<ReactionWheel>&);
		void EnergyToReactionWheel(int index, double work);//work - energy that the wheel receivs from engine
		void MoveAndRotate(double time) override;
		~Sattelite();
	};

}

