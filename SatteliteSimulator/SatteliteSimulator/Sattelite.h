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
	public:
		Sattelite(string name, vector<MassPoint>& mPoints, vector<ForcePoint>& fPoints, vector<ReactionWheel>& wheels);
		void SetReactionWheelSpeed(int index, double speed);
		void MoveAndRotate(double time) override;
		~Sattelite();
	};

}

