#pragma once
#include<vector>

#include"MassPoint.h"
#include"ForcePoint.h"
#include"IObject.h"

using namespace std;

namespace simulator
{

	class Object : IObject
	{
	private:
		string _name;
		struct Rotation
		{
			Vector3d AxisVector;
			Point AxisPoint;
			double AngleSpeed; // radiant per second
		};
	protected:
		double _inertiaX; // kg per meter^2
		double _inertiaY; // kg per meter^2
		double _inertiaZ; // kg per meter^2

		Rotation _rotationX;
		Rotation _rotationY;
		Rotation _rotationZ;

		vector<MassPoint> _mPoints;
		MassPoint _massCentre;

		void Init();
		pair<Vector3d, Vector3d> GetForceComponents(int fPointIndex);
	public:
		explicit Object(string name, vector<MassPoint>& mPoints);
		void PowerToPoint(int fPointIndex, double force, double forceDuration);
		void MoveAndRotate(double time);
		Vector3d GetInertia();
		void LogInfo(ostream& out);
		Vector3d GetRotationSpeeds();
		Point GetPoint(int index, char type);
		void AddMassPoint(MassPoint mPoint);
		~Object();
	};

}