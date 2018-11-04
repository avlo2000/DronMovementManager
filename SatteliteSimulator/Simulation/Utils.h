#pragma once
#include<vector>
#include"Point.h"
#include"MassPoint.h"
#define SQR(x) pow(x, 2.0)

namespace Simulator
{
	inline double SqrDistance(Point p1, Point p2)
	{
		return SQR(p1.X() - p2.X()) + SQR(p1.Y() - p2.Y()) + SQR(p1.Z() - p2.Z());
	}

	inline double GetVecLength(Vector3d vec)
	{
		return sqrt(SQR(vec.x()) + SQR(vec.y()) + SQR(vec.z()));
	}

	inline Vector3d PrjVecOnVec(Vector3d prjVec, Vector3d targetVec)
	{
		double prjLen = (prjVec.transpose() * targetVec).sum() / GetVecLength(targetVec);
		double corrCoef = prjLen / GetVecLength(targetVec);
		return Vector3d(corrCoef * targetVec.x(), corrCoef * targetVec.y(), corrCoef * targetVec.z());
	}

	inline Vector3d InstSpeedFromImpuls(double mass, Vector3d currentSpeed, Vector3d force, double time)
	{
		Vector3d resultSpeed = (mass * currentSpeed - force * time) / mass;
		return resultSpeed;
	}

	inline double RotationSpeedFromRotImpuls(double inertMoment, double moment, double time)
	{
		double rotSpeed = inertMoment * moment * time;
		return rotSpeed;
	}

	inline Vector3d GetPerpendicularVec(Vector3d vec1, Vector3d vec2)
	{
		Vector3d scal(vec2.y() * vec1.z() - vec1.y() * vec2.z(),
			vec1.x() * vec2.z() - vec2.x() * vec1.z(),
			vec2.x() * vec1.y() - vec1.x() * vec2.y());
		double x = scal.x() / GetVecLength(scal);
		double y = scal.y() / GetVecLength(scal);
		double z = scal.z() / GetVecLength(scal);
		return Vector3d(x, y, z);
	}

	inline Vector3d RotateVector(Vector3d vector, Vector3d axesVector, Point axesPoint, double angle)
	{
		Vector4d _vector(vector.x(), vector.y(), vector.z(), 1.0);
		Vector3d currentAxesPoint(axesPoint.X(), axesPoint.Y(), axesPoint.Z());
		Affine3d affineTransformation = Translation3d(currentAxesPoint) * AngleAxisd(angle, axesVector) * Translation3d(-currentAxesPoint);
		_vector = (affineTransformation.matrix() * _vector);
		return Vector3d(_vector.x(), _vector.y(), _vector.z());
	}

	inline Point RotatePoint(Point point, Vector3d axesVector, Point axesPoint, double angle)
	{
		Vector4d _point(point.X(), point.Y(), point.Z(), 1.0);
		Vector3d currentAxesPoint(axesPoint.X(), axesPoint.Y(), axesPoint.Z());
		Affine3d affineTransformation = Translation3d(currentAxesPoint) * AngleAxisd(angle, axesVector) * Translation3d(-currentAxesPoint);
		_point = (affineTransformation.matrix() * _point);
		double x = _point.x();
		double y = _point.y();
		double z = _point.z();
		return Point(x, y, z);
	}
}
