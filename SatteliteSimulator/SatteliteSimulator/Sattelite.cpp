#include "Satellite.h"

namespace simulator
{
	void Satellite::Init()
	{
		//start impuls is not included [Imp1 + Imp2 = 0]
		double rotImpX = 0;
		double rotImpY = 0;
		double rotImpZ = 0;

		for (int index = 0; index < _reactionWheels.size(); index++)
		{
			rotImpX -= _reactionWheels[index].GetMomentumImpuls().x();
			rotImpY -= _reactionWheels[index].GetMomentumImpuls().y();
			rotImpZ -= _reactionWheels[index].GetMomentumImpuls().z();
		}


		this->_rotationX.AngleSpeed = rotImpX / this->_inertiaX;
		this->_rotationY.AngleSpeed = rotImpY / this->_inertiaY;
		this->_rotationZ.AngleSpeed = rotImpZ / this->_inertiaZ;
	}
	Satellite::Satellite(string name, vector<MassPoint>& mPoints, vector<ForcePoint>& fPoints, vector<ReactionWheel>& wheels)
		: Object(name, mPoints, fPoints)
	{
		this->_reactionWheels = wheels;
		this->_mPoints.insert(this->_mPoints.end(), this->_reactionWheels.begin(), this->_reactionWheels.end());
		Object::Init();
	}

	void Satellite::EnergyToReactionWheel(int index, double work)
	{
		this->_reactionWheels[index].PowerToWheel(work);

		Init();
	}

	void Satellite::MoveAndRotate(double time)
	{


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
		Init();
	}

	int Satellite::GetNumOfWheels() {
		return this->_reactionWheels.size();
	}

	Satellite::~Satellite()
	{
	}

}
