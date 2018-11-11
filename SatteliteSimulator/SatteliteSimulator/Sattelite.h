#pragma once
#include "Object.h"
#include "ReactionWheel.h"

namespace Simulator 
{

	class Sattelite : public Object
	{
	private:
		vector<ReactionWheel> _reactionWheels;
	public:
		Sattelite(vector<MassPoint>& mPoints, vector<ForcePoint>& fPoints, vector<ReactionWheel>& wheels);
		void SetReactionWheelSpeed(int index, double speed);
		void MoveAndRotate(double time) override;
		~Sattelite();
	};

}

