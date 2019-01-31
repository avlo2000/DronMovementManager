#pragma once
#include "Command.h"
class ControlCommand :
	public Command
{
public:
	ControlCommand() {};
	~ControlCommand() {};

	// Inherited via Command
	string name() override
	{
		return this->commands.control;
	};
	void Execute(string params) override
	{
		auto parse = Split(params, ' ');
		string name = parse[1];
		string::size_type sz;
		double xRot = stod(parse[2], &sz);
		double yRot = stod(parse[3], &sz);
		double zRot = stod(parse[4], &sz);
		Vector3d vec(xRot, yRot, zRot);
		global.Control(vec, name);
		this->Log("\n...controller has worked out...\n");
	};
};

