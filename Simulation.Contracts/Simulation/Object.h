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
		struct Rotation 
		{
			Vector3d AxisVector;
			Point AxisPoint;
			double AngleSpeed;
		};
		vector<Rotation> _rotations;

		vector<ForcePoint> _fPoints;
		vector<MassPoint> _mPoints;
		MassPoint _massCentre;
		Vector3d _instSpeed; 
		double _inertMoment;

		void Init();
		pair<Vector3d, Vector3d> GetForceComponents(int fPointIndex);
	public:
		Object(vector<MassPoint> mPoints, vector<ForcePoint> fPoints);
		void PowerToPoint(int fPointIndex, double force, double forceDuration);
		void MoveAndRotate(double time);
		double GetInertMoment();
		void LogInfo(ostream& out);
		Point GetPoint(int index, char type);
		~Object();
	};

}