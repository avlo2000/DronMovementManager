#include "Sattelite.h"

namespace Simulator
{
	Sattelite::Sattelite(vector<MassPoint>& mPoints, vector<ForcePoint>& fPoints, vector<ReactionWheel>& wheels)
		: Object(mPoints, fPoints)
	{
		this->_reactionWheels = wheels;
		this->_mPoints.insert(this->_mPoints.end(), this->_reactionWheels.begin(), this->_reactionWheels.end());
		Object::Init();
	}

	void Sattelite::SetReactionWheelSpeed(int index, double speed)
	{
		this->_reactionWheels[index].SetSpeed(speed);
		
	}

	void Sattelite::MoveAndRotate(double time)
	{
		double rotImpX = this->_rotationX.AngleSpeed * this->_inertiaX;
		double rotImpY = this->_rotationY.AngleSpeed * this->_inertiaY;
		double rotImpZ = this->_rotationZ.AngleSpeed * this->_inertiaZ;

		for(auto wheel : this->_reactionWheels)
		{
			rotImpX -= wheel.GetMomentumImpuls().x();
			rotImpY -= wheel.GetMomentumImpuls().y();
			rotImpZ -= wheel.GetMomentumImpuls().z();
		}

		this->_rotationX.AngleSpeed = rotImpX / this->_inertiaX;
		this->_rotationY.AngleSpeed = rotImpY / this->_inertiaY;
		this->_rotationZ.AngleSpeed = rotImpZ / this->_inertiaZ;

		Object::MoveAndRotate(time);

		for (auto wheel = this->_reactionWheels.begin(); wheel < this->_reactionWheels.end(); wheel++)
		{
			(*wheel).SetInstSpeed(this->_instSpeed);
			(*wheel).Move(time);

			(*wheel).SetRotation(this->_rotationX.AxisVector, this->_rotationX.AxisPoint, this->_rotationX.AngleSpeed);
			(*wheel).Rotate(time);

			(*wheel).SetRotation(this->_rotationY.AxisVector, this->_rotationY.AxisPoint, this->_rotationY.AngleSpeed);
			(*wheel).Rotate(time);

			(*wheel).SetRotation(this->_rotationZ.AxisVector, this->_rotationZ.AxisPoint, this->_rotationZ.AngleSpeed);
			(*wheel).Rotate(time);
		}
	}

	Sattelite::~Sattelite()
	{
	}

}
