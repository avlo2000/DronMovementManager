#pragma once
#include "Object.h"
#include "Utils.h"
#include <iostream>

namespace Simulator
{

	void Object::Init()
	{
		double mass = 0;
		double xSum = 0;
		double ySum = 0;
		double zSum = 0;
		this->_inertMoment = 0;

		for (auto mPoint : this->_mPoints)
		{
			mass += mPoint.GetMass();
			xSum += mPoint.GetMass() * mPoint.X();
			ySum += mPoint.GetMass() * mPoint.Y();
			zSum += mPoint.GetMass() * mPoint.Z();
		}


		this->_massCentre = MassPoint(mass, xSum / mass, ySum / mass, zSum / mass);

		for (auto mPoint : this->_mPoints)
		{
			double d = SqrDistance(this->_massCentre, mPoint);
			this->_inertMoment += mPoint.GetMass() * SqrDistance(this->_massCentre, mPoint);
		}

	}

	pair<Vector3d, Vector3d> Object::GetForceComponents(int fPointIndex)
	{
		Vector3d axis(this->_fPoints[fPointIndex].X() - this->_massCentre.X(),
			this->_fPoints[fPointIndex].Y() - this->_massCentre.Y(), 
			this->_fPoints[fPointIndex].Z() - this->_massCentre.Z());

		Vector3d instForce = PrjVecOnVec(this->_fPoints[fPointIndex].GetForce(), axis);
		Vector3d rotateForce = _fPoints[fPointIndex].GetForce() - instForce;

		return pair<Vector3d, Vector3d>(instForce, rotateForce);
	}

	Object::Object(vector<MassPoint> mPoints, vector<ForcePoint> fPoints)
	{
		this->_fPoints = fPoints;
		this->_mPoints = mPoints;

		this->Init();
	}

	void Object::PowerToPoint(int fPointIndex, double force, double forceDuration)
	{
		this->_fPoints[fPointIndex].SetForce(force);

		pair<Vector3d, Vector3d> forceComponents = GetForceComponents(fPointIndex);
		
		Vector3d instComponent = forceComponents.first;
		Vector3d rotComponent = forceComponents.second;

		//Instante speed change
		//--------------------
		this->_instSpeed = InstSpeedFromImpuls(this->_massCentre.GetMass(),
			this->_instSpeed, instComponent, forceDuration);
		//---------------------


		//Object rotation change
		//--------------------
		Vector3d centre_fpoint(this->_fPoints[fPointIndex].X() - this->_massCentre.X(),
			this->_fPoints[fPointIndex].Y() - this->_massCentre.Y(),
			this->_fPoints[fPointIndex].Z() - this->_massCentre.Z());

		Rotation newRotation;
		newRotation.AxisPoint = this->_massCentre;
		newRotation.AxisVector = GetPerpendicularVec(rotComponent, centre_fpoint);

		double forceRadius = sqrt(SqrDistance(this->_massCentre, _fPoints[fPointIndex]));
		Vector3d moment = forceRadius * rotComponent;
		newRotation.AngleSpeed = RotationSpeedFromRotImpuls(this->_inertMoment, moment, forceDuration);

		this->_rotations.push_back(newRotation);
		//--------------------
	}

	void Object::MoveAndRotate(double time)
	{
		this->_massCentre.SetInstSpeed(this->_instSpeed);
		this->_massCentre.Move(time);

		for (auto point = this->_fPoints.begin(); point < this->_fPoints.end(); point++)
		{
			(*point).SetInstSpeed(this->_instSpeed);
			(*point).Move(time);
			
			for (Rotation rotation : this->_rotations)
			{
				(*point).SetRotation(rotation.AxisVector, rotation.AxisPoint, rotation.AngleSpeed);
				(*point).Rotate(time);
			}
		}

		for (auto point = this->_mPoints.begin(); point < this->_mPoints.end(); point++)
		{
			(*point).SetInstSpeed(this->_instSpeed);
			(*point).Move(time);

			for (Rotation rotation : this->_rotations)
			{
				(*point).SetRotation(rotation.AxisVector, rotation.AxisPoint, rotation.AngleSpeed);
				(*point).Rotate(time);
			}
		}
	}

	double Object::GetInertMoment()
	{
		return this->_inertMoment;
	}

	void Object::LogInfo(ostream& out)
	{
		out << "Instanse speed vector: " << this->_instSpeed.x() << " "
			<< this->_instSpeed.y() << " "
			<< this->_instSpeed.z() << endl;
		out << "Moment of inertion: " << this->_inertMoment << endl;
		out << "Position of centre of mass: " << this->_massCentre.X() << " "
			<< this->_massCentre.Y()<<" "
			<< this->_massCentre.Z() << endl;
		out << endl;
	}

	Object::~Object()
	{
	}

}
