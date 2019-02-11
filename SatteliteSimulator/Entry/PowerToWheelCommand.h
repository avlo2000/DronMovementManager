#pragma once
#include "Command.h"
class PowerToWheelCommand :
	public Command
{
public:
	PowerToWheelCommand() {};
	~PowerToWheelCommand() {};

	// Inherited via Command
	virtual string name() override
	{
		return this->commands.powerToWheel;
	};
	virtual void Execute(string params) override
	{
		auto parse = Split(params, ' ');

		string name = parse[3];
		string::size_type sz;
		int index = stoi(parse[4], &sz);
		double power = stod(parse[5], &sz);

		this->Log("\n...powering the wheel...\n");
		auto obj = this->global.GetController(name)->GetRegistration();
		obj->EnergyToReactionWheel(index + 1, power);
		this->Log("\n...power of reaction wheel was changed...\n");
	};
};

