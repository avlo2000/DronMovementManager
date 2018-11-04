#pragma once
#include<Eigen/Dense>
#include<Eigen/Geometry>
#include"IRotatable.h"
#include"MassPoint.h"
using namespace Eigen;
using namespace Contracts;

namespace Simulator {

	class ReactionWheel : public MassPoint
	{
	private:
		Vector3d _rotAxes;
		double _speed; // radians per second
		double _inertia; // kg per meter^2
		Vector3d _rotImpuls;
		double _heatLoss; // radians per second^2
		Vector3d _instSpeed;

		void Init();
	public:
		ReactionWheel(double mass, double x, double y, double z, Vector3d rotAxes, double inertia);
		double GetSpeed();
		void SetSpeed(double speed);
		void SetRotation(Vector3d axesVector, Point axesPoint, double rotSpeed);
		Vector3d GetMomentumImpuls();
		~ReactionWheel();

		virtual void Rotate(double time) override;
	};

}

