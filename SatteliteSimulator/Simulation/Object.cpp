#pragma once
#include "Object.h"
#include "Exceptions.h"
#include "Utils.h"
#include <iostream>

namespace simulator
{

	void Object::Init()
	{
		double mass = 0;
		double xSum = 0;
		double ySum = 0;
		double zSum = 0;
		this->_inertiaX = 0;
		this->_inertiaY = 0;
		this->_inertiaZ = 0;

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
			this->_inertiaX += mPoint.GetMass() * SQR(_massCentre.X() - mPoint.X());
			this->_inertiaY += mPoint.GetMass() * SQR(_massCentre.Y() - mPoint.Y());
			this->_inertiaZ += mPoint.GetMass() * SQR(_massCentre.Z() - mPoint.Z());
		}

		this->_rotationX = Rotation({ Vector3d(1, 0, 0), this->_massCentre, 0 });
		this->_rotationY = Rotation({ Vector3d(0, 1, 0), this->_massCentre, 0 });
		this->_rotationZ = Rotation({ Vector3d(0, 0, 1), this->_massCentre, 0 });
	}

	pair<Vector3d, Vector3d> Object::GetForceComponents(int fPointIndex)
	{
		Vector3d axis(this->_fPoints[fPointIndex].X() - this->_massCentre.X(),
			this->_fPoints[fPointIndex].Y() - this->_massCentre.Y(), 
			this->_fPoints[fPointIndex].Z() - this->_massCentre.Z());

		if(GetVecLength(axis)==0)
			return pair<Vector3d, Vector3d>(this->_fPoints[fPointIndex].GetForce(), Vector3d(0, 0, 0));

		Vector3d instForce = PrjVecOnVec(this->_fPoints[fPointIndex].GetForce(), axis);
		Vector3d rotateForce = _fPoints[fPointIndex].GetForce() - instForce;

		return pair<Vector3d, Vector3d>(instForce, rotateForce);
	}

	Object::Object(string name, vector<MassPoint>& mPoints, vector<ForcePoint>& fPoints)
	{
		this->_name = name;
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
		Vector3d forceRadius(this->_fPoints[fPointIndex].X() - this->_massCentre.X(),
			this->_fPoints[fPointIndex].Y() - this->_massCentre.Y(),
			this->_fPoints[fPointIndex].Z() - this->_massCentre.Z());

		Vector3d moment = forceRadius.cross(rotComponent);

		this->_rotationX.AngleSpeed += RotationSpeedFromRotImpuls(this->_inertiaX, moment.x(), forceDuration);
		this->_rotationY.AngleSpeed += RotationSpeedFromRotImpuls(this->_inertiaY, moment.y(), forceDuration);
		this->_rotationZ.AngleSpeed += RotationSpeedFromRotImpuls(this->_inertiaZ, moment.z(), forceDuration);
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
			
			(*point).SetRotation(this->_rotationX.AxisVector, this->_rotationX.AxisPoint, this->_rotationX.AngleSpeed);
			(*point).Rotate(time);

			(*point).SetRotation(this->_rotationY.AxisVector, this->_rotationY.AxisPoint, this->_rotationY.AngleSpeed);
			(*point).Rotate(time);

			(*point).SetRotation(this->_rotationZ.AxisVector, this->_rotationZ.AxisPoint, this->_rotationZ.AngleSpeed);
			(*point).Rotate(time);
		}

		for (auto point = this->_mPoints.begin(); point < this->_mPoints.end(); point++)
		{
			(*point).SetInstSpeed(this->_instSpeed);
			(*point).Move(time);

			(*point).SetRotation(this->_rotationX.AxisVector, this->_rotationX.AxisPoint, this->_rotationX.AngleSpeed);
			(*point).Rotate(time);

			(*point).SetRotation(this->_rotationY.AxisVector, this->_rotationY.AxisPoint, this->_rotationY.AngleSpeed);
			(*point).Rotate(time);

			(*point).SetRotation(this->_rotationZ.AxisVector, this->_rotationZ.AxisPoint, this->_rotationZ.AngleSpeed);
			(*point).Rotate(time);
		}
	}

	Vector3d Object::GetInertia()
	{
		return Vector3d(this->_inertiaX, this->_inertiaY, this->_inertiaZ);
	}

	void Object::LogInfo(ostream& out)
	{
		out << "Info of " << this->_name << " :" << endl;
		out << "Instanse speed vector: " 
			<<	this->_instSpeed.x() << " "
			<< this->_instSpeed.y() << " "
			<< this->_instSpeed.z() << endl;
		out << "Rotation speed vector: " 
			<< this->_rotationX.AngleSpeed << " "
			<< this->_rotationY.AngleSpeed << " "
			<< this->_rotationZ.AngleSpeed << endl;
		out << "Position of centre of mass: " 
			<< this->_massCentre.X() << " "
			<< this->_massCentre.Y()<<" "
			<< this->_massCentre.Z() << endl;
		out << endl;
	}

	Vector3d Object::GetRotationSpeeds()
	{
		return Vector3d(this->_rotationX.AngleSpeed, 
			this->_rotationY.AngleSpeed, 
			this->_rotationZ.AngleSpeed);
	}

	Point Object::GetPoint(int index, char type)
	{
		if(type == 'f')
			return this->_fPoints[index];
		if (type == 'm')
			return this->_mPoints[index];
		throw WrongPointTypeException();
	}

	void Object::AddMassPoint(MassPoint mPoint)
	{
		this->_mPoints.push_back(mPoint);
		double mass = this->_massCentre.GetMass() + mPoint.GetMass();

		double x = mPoint.GetMass() * mPoint.X();
		double y = mPoint.GetMass() * mPoint.Y();
		double z = mPoint.GetMass() * mPoint.Z();
		this->_massCentre = MassPoint(mass, x / mass, y / mass, z / mass);

		this->_inertiaX += mPoint.GetMass() * SQR(_massCentre.X() - mPoint.X());
		this->_inertiaY += mPoint.GetMass() * SQR(_massCentre.Y() - mPoint.Y());
		this->_inertiaZ += mPoint.GetMass() * SQR(_massCentre.Z() - mPoint.Z());

		this->_rotationX = Rotation({ Vector3d(1, 0, 0), this->_massCentre, 0 });
		this->_rotationY = Rotation({ Vector3d(0, 1, 0), this->_massCentre, 0 });
		this->_rotationZ = Rotation({ Vector3d(0, 0, 1), this->_massCentre, 0 });
	}

	Object::~Object()
	{
	}

}
