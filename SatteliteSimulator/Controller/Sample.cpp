#pragma once
#include"Sample.h"
namespace simulator {
	void Sample::AddEnergy(VectorXd &vec) {
		_energy.push_back(vec);
	}
	void Sample::AddRotSpeed(VectorXd &vec) {
		_rotSpeed.push_back(vec);
	}
	MatrixXd Sample::ConvertToMatrix(vector<VectorXd> &vec) {
		MatrixXd matrix(vec.at(0).size(), vec.size());
		for (int i = 0; i < matrix.cols(); i++) {
			for (int j = 0; j < matrix.rows(); j++) {
				matrix(j, i) = vec.at(i)(j);
			}
		}
		return matrix;
	}
	VectorXd Sample::ConvertVector3dToXd(Vector3d &vec) {
		VectorXd newVec(3);
		for (int i = 0; i < 3; i++) {
			newVec(i) = vec(i);
		}
		return newVec;
	}
	MatrixXd Sample::GetEnergy() {
		return ConvertToMatrix(_energy);
	}
	MatrixXd Sample::GetRotSpeed() {
		return ConvertToMatrix(_rotSpeed);
	}
}