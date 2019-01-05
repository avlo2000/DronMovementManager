#pragma once
#include "Object.h"
#include "ReactionWheel.h"
#include "IControlable.h"

namespace simulator 
{

	class Satellite : IControlable, public Object
	{
	private:
		vector<ReactionWheel> _reactionWheels;
		void Init();
	public:
		Satellite(string name, vector<MassPoint>&, vector<ForcePoint>& , vector<ReactionWheel>&);
		void EnergyToReactionWheel(int index, double work);//work - energy that the wheel receivs from engine
		void MoveAndRotate(double time) override;
		int GetNumOfWheels();
		~Satellite();

		// Inherited via IControlable
		virtual void RegisterControl(IController<Object>* controller) override;
		virtual void Control(Vector3d instSpeed, Vector3d rotSpeed) override;
	};

}

