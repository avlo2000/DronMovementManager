#pragma once
#include<vector>

#include"MassPoint.h"
#include"ForcePoint.h"
#include"IObject.h"

namespace Simulator
{

	class Object : IObject
	{
	private:
		//first - rotation centre
		//second - vector of speed of rotation
		vector<pair<Vector3d, Vector3d>> _rotations;

		vector<ForcePoint> _fPoints;
		vector<MassPoint> _mPoints;
		MassPoint _massCentre;
		double _inertMoment;

		void Init();
	public:
		Object(vector<MassPoint> mPoints, vector<ForcePoint> fPoints);
		~Object();
	};

}