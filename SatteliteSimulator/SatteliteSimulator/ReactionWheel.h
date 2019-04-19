#pragma once
#include<Eigen/Dense>
#include<Eigen/Geometry>
#include"IRotatable.h"
#include"MassPoint.h"
using namespace Eigen;
using namespace contracts;

namespace simulator {

	class ReactionWheel : public MassPoint
	{
	private:
		Vector3d _rotAxes;
		double _speed; // [radians per second]
		double _inertia; // [kg per meter^2]
		Vector3d _rotImpuls;
		double _frictionCoef;
		Vector3d _instSpeed;

		void Init();
	public:
		ReactionWheel(double mass, double x, double y, double z, Vector3d rotAxes, double radius);
		double GetSpeed();
		double GetEnergy();
		void PowerToWheel(double work);//work - energy that the wheel receivs from engine
		void SetFrictionCoef(double friction); 
		void SetRotation(Vector3d axesVector, Point axesPoint, double rotSpeed);
		Vector3d GetMomentumImpuls();
		~ReactionWheel();

		virtual void Rotate(double time) override;
	};

}

