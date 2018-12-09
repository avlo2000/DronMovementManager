#include "ReactionWheel.h"
#include "Utils.h"

namespace simulator {

	void ReactionWheel::Init()
	{
		this->_rotAxes.normalize();
		this->_rotImpuls = this->_speed * this->_inertia * this->_rotAxes;
	}

	ReactionWheel::ReactionWheel(double mass, double x, double y, double z, Vector3d rotAxes, double radius)
		: MassPoint(mass, x, y, z)
	{
		this->_inertia = mass * SQR(radius) / 2;
		this->_rotAxes = rotAxes;
		this->_speed = 0;
		this->_frictionCoef = 0;
		Init();
	}

	double ReactionWheel::GetSpeed()
	{
		return this->_speed;
	}

	void ReactionWheel::PowerToWheel(double work)
	{
		work = -work;

		if(work > 0)
			this->_speed = sqrt(abs(SQR(this->_speed) - 2 * abs(work) / this->_inertia));
		else
			this->_speed = -sqrt(abs(SQR(this->_speed) - 2 * abs(work) / this->_inertia));

		this->Init();
	}

	void ReactionWheel::SetFrictionCoef(double friction)
	{
		this->_frictionCoef = friction;
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

		this->_rotAxes = RotateVector(this->_rotAxes, this->axesVector, Point(0, 0, 0), angle);

		//TO DO(include friction)
		this->Init();
	}
}