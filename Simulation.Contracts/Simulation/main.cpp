#include "Object.h"
#include <iostream>

using namespace Simulator;
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>
# define M_PI           3.14159265358979323846

int main()
{
	vector<MassPoint> mPoints;
	vector<ForcePoint> fPoints;
	mPoints.push_back(MassPoint(1, 1, 0, 0));
	mPoints.push_back(MassPoint(1, -1, 0, 0));
	mPoints.push_back(MassPoint(1, 0, 0, 0));
	fPoints.push_back(ForcePoint(Vector3d(0, 1, 0), 1, 0, 0));
	Object obj(mPoints, fPoints);
	obj.PowerToPoint(0, 1, 1);
	obj.LogInfo(cout);
	cout << obj.GetPoint(0, 'm').X() << " ";
	cout << obj.GetPoint(0, 'm').Y() << " ";
	cout << obj.GetPoint(0, 'm').Z() << endl;
	cout << obj.GetPoint(1, 'm').X() << " ";
	cout << obj.GetPoint(1, 'm').Y() << " ";
	cout << obj.GetPoint(1, 'm').Z() << endl;
	obj.MoveAndRotate(1);
	cout << endl;
	obj.LogInfo(cout);
	cout << obj.GetPoint(0, 'm').X() << " ";
	cout << obj.GetPoint(0, 'm').Y() << " ";
	cout << obj.GetPoint(0, 'm').Z() << endl;
	cout << obj.GetPoint(1, 'm').X() << " ";
	cout << obj.GetPoint(1, 'm').Y() << " ";
	cout << obj.GetPoint(1, 'm').Z() << endl;
	obj.MoveAndRotate(1);
	cout << endl;
	obj.LogInfo(cout);
	cout << obj.GetPoint(0, 'm').X() << " ";
	cout << obj.GetPoint(0, 'm').Y() << " ";
	cout << obj.GetPoint(0, 'm').Z() << endl;
	cout << obj.GetPoint(1, 'm').X() << " ";
	cout << obj.GetPoint(1, 'm').Y() << " ";
	cout << obj.GetPoint(1, 'm').Z() << endl;
	obj.MoveAndRotate(1);
	cout << endl;
	obj.LogInfo(cout);
	cout << obj.GetPoint(0, 'm').X() << " ";
	cout << obj.GetPoint(0, 'm').Y() << " ";
	cout << obj.GetPoint(0, 'm').Z() << endl;
	cout << obj.GetPoint(1, 'm').X() << " ";
	cout << obj.GetPoint(1, 'm').Y() << " ";
	cout << obj.GetPoint(1, 'm').Z() << endl;
	system("pause");
	return 0;
}