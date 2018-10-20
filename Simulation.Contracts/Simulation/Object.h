#include<vector>

#include"Point.h"
#include"MassPoint.h"
#include"ForcePoint.h"
#include"IObject.h"

class Object : IObject
{
private:
	//first - rotation centre
	//second - vector of speed of rotation
	vector<pair<Vector3d, Vector3d>> _rotations;

	vector<ForcePoint> _fPoints;
	vector<MassPoint> _mPoints;
	double _inertMoment;

	void Init();
public:
	Object(vector<MassPoint> mPoints, vector<ForcePoint> fPoints);
	~Object();
};