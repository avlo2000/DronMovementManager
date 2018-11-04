#include "Sattelite.h"
#include <iostream>

using namespace Simulator;
using namespace std;

int main()
{
	vector<MassPoint> mPoints;
	vector<ForcePoint> fPoints;
	vector<ReactionWheel> wheels;
	mPoints.push_back(MassPoint(1, 1, 0, 0));
	mPoints.push_back(MassPoint(1, -1, 0, 0));
	mPoints.push_back(MassPoint(1, 0, 1, 0));
	mPoints.push_back(MassPoint(1, 0, -1, 0));
	mPoints.push_back(MassPoint(1, 0, 0, 1));
	wheels.push_back(ReactionWheel(1, 0, 0, -1, Vector3d(0, 1, 0), 3));

	Sattelite obj(mPoints, fPoints, wheels);
	obj.SetReactionWheelSpeed(0, 1);

	obj.LogInfo(cout);
	cout << "Dist: " << sqrt(SqrDistance(obj.GetPoint(1, 'm'), obj.GetPoint(2, 'm'))) << endl;
	obj.MoveAndRotate(1);
	cout << endl;
	obj.LogInfo(cout);
	cout << "Dist: " << sqrt(SqrDistance(obj.GetPoint(1, 'm'), obj.GetPoint(2, 'm'))) << endl;
	obj.MoveAndRotate(1);
	cout << endl;
	obj.LogInfo(cout);
	cout << "Dist: " << sqrt(SqrDistance(obj.GetPoint(1, 'm'), obj.GetPoint(2, 'm'))) << endl;
	obj.MoveAndRotate(1);
	cout << endl;
	obj.LogInfo(cout);
	cout << "Dist: " << sqrt(SqrDistance(obj.GetPoint(1, 'm'), obj.GetPoint(2, 'm'))) << endl;
	system("pause");
	return 0;
}