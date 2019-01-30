#pragma once
#include "Command.h"
#include "DefaultSatellite.h"

namespace simulator {

	class AddDefaultSatCommand : public Command
	{
	public:
		AddDefaultSatCommand() {};
		virtual AddDefaultSatCommand* create() { return new AddDefaultSatCommand; }
		void Execute(std::string params) override
		{
			auto str = Split(params, ' ').at(2);
			Satellite *sat = &CreateSatellite(Split(params, ' ').at(3));
			global.AddObject(*sat);
			this->Log("Default satellite was created with name " + Split(params, ' ').at(3));
		};
		string name() override
		{
			return this->commands.createDefault;
		}
		~AddDefaultSatCommand() {};
	};

}
