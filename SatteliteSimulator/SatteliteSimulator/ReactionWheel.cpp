#include "ReactionWheel.h"
#include "Utils.h"

namespace simulator {

	void ReactionWheel::Init()
	{
		this->_rotAxes.normalize();
		this->_rotImpuls = this->_speed * this->_inertia * this->_rotAxes;
	}

	ReactionWheel::ReactionWheel(double mass, double x, double y, double z, Vector3d rotAxes, double inertia)
		: MassPoint(mass, x, y, z)
	{
		this->_inertia = inertia;
		this->_rotAxes = rotAxes;
		this->_speed = 0;
		this->_heatLoss = 0;
	}

	double ReactionWheel::GetSpeed()
	{
		return this->_speed;
	}

	void ReactionWheel::SetSpeed(double speed)
	{
		this->_speed = speed;
		Init();
	}

	void ReactionWheel::SetRotation(Vector3d axesVector, Point axesPoint, double rotSpeed)
	{
		this->axesVector = axesVector;
		this->axesPoint = Vector3d(axesPoint.X(), axesPoint.Y(), axesPoint.Z());
		this->rotSpeed = rotSpeed;
	}

	Vector3d ReactionWheel::GetMomentumImpuls()
	{
		return this->_rotImpuls;
	}

	ReactionWheel::~ReactionWheel()
	{
	}
	void ReactionWheel::Rotate(double time)
	{
		MassPoint::Rotate(time);

		double angle = this->rotSpeed * time;

		this->_rotAxes = RotateVector(this->_rotAxes, this->axesVector, Point(this->axesPoint.x(),
			this->axesPoint.y(), this->axesPoint.z()), angle);

		if(this->_speed > 0)
			this->_speed -= time * this->_heatLoss;
		else
			this->_speed += time * this->_heatLoss;
		this->Init();
	}
}