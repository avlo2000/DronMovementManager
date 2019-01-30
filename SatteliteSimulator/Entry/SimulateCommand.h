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
			//TO DO
		};
		string name() override
		{
			// TO DO
			return this->commands.createDefault;
		}
		~AddDefaultSatCommand() {};
	};

}