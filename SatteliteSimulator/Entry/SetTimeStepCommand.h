#pragma once
#include "Command.h"

namespace simulator {

	class SetTimeStepCommand :
		public Command
	{
	public:
		SetTimeStepCommand() {};
		~SetTimeStepCommand() {};

		// Inherited via Command
		string name() override
		{
			return this->commands.simStep;
		};
		void Execute(string params) override
		{
			string::size_type sz;
			auto str = Split(params, ' ').at(2);
			double time = stod(str, &sz);
			this->global.SetTimeStep(time);
			this->Log("\n...time step has been setted...\n");
		};
	};

}