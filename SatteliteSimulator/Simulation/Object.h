#pragma once
#include<vector>

#include"MassPoint.h"
#include"ForcePoint.h"
#include"IObject.h"

using namespace std;

namespace simulator
{

	class Object : public IObject
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

		vector<ForcePoint> _fPoints;
		vector<MassPoint> _mPoints;
		MassPoint _massCentre;
		Vector3d _instSpeed; 

		void Init();
		pair<Vector3d, Vector3d> GetForceComponents(int fPointIndex);
	public:
		explicit Object(string name, vector<MassPoint>& mPoints, vector<ForcePoint>& fPoints);
		void PowerToPoint(int fPointIndex, double force, double forceDuration);
		virtual void Move(double time);
		virtual void Rotate(double time);
		Vector3d GetInertia();
		void LogInfo(ostream& out);
		Vector3d GetRotationSpeeds();
		Point GetPoint(int index, char type);
		void AddMassPoint(MassPoint mPoint);
		~Object();
	};

}