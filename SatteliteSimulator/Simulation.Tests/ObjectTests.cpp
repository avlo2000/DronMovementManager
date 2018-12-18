#pragma once
#include "gtest/gtest.h"
#include "pch.h"
#include "Mockups.h"

TEST(ObjectTest1, TestStartSpeedsSim) {
	auto obj = SimetricalObject();
	EXPECT_EQ(obj.GetRotationSpeeds(), Vector3d(0, 0, 0));
	EXPECT_TRUE(true);
}

TEST(ObjectTest2, TestStartSpeedsAsim) {
	auto obj = AsimetricalObject();
	EXPECT_EQ(obj.GetRotationSpeeds(), Vector3d(0, 0, 0));
	EXPECT_TRUE(true);
}

TEST(ObjectTest3, TestStartSpeedsAsim) {
	auto obj = SimetricalObject();
	auto pnt0 = obj.GetPoint(0, 'f');
	obj.PowerToPoint(1, 5, 0.1);
	obj.MoveAndRotate(1);
	auto pnt1 = obj.GetPoint(0, 'f');
	EXPECT_EQ(obj.GetRotationSpeeds(), Vector3d(0, 0, 0));
	EXPECT_TRUE(true);
}
