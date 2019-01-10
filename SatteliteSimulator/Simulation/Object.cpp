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

	Object::Object(string name, vector<MassPoint>& mPoints)
	{
		this->_name = name;
		this->_mPoints = mPoints;

		this->Init();
	}


	void Object::MoveAndRotate(double time)
	{

		for (auto point = this->_mPoints.begin(); point < this->_mPoints.end(); point++)
		{
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
		out << "Rotation speed vector(radians per sec): " 
			<< this->_rotationX.AngleSpeed << " "
			<< this->_rotationY.AngleSpeed << " "
			<< this->_rotationZ.AngleSpeed << endl;
		out << "Position of centre of mass(meters): " 
			<< this->_massCentre.X() << " "
			<< this->_massCentre.Y()<<" "
			<< this->_massCentre.Z() << endl;
		out << "Rotation kinetic energy: " << (SQR(this->_rotationX.AngleSpeed) * this->_inertiaX +
			SQR(this->_rotationY.AngleSpeed) * this->_inertiaY 
			+ SQR(this->_rotationZ.AngleSpeed) * this->_inertiaZ) / 2 << endl;
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
