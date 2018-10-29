#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Object.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Simulator;
using namespace std;

namespace SimulationTests
{
	TEST_CLASS(ObjectTest)
	{
	public:
		
		TEST_METHOD(MomentOfInertionTest)
		{
			vector<MassPoint> mPoints;
			vector<ForcePoint> fPoints;
			mPoints.push_back(MassPoint(2, 1, 0, 0));
			mPoints.push_back(MassPoint(2, -1, 0, 0));
			Object obj(mPoints, fPoints);
			Assert::AreEqual(obj.GetInertMoment(), 4.0);
		}

	};
}