#pragma once
#include "Command.h"
#include "DefaultSatellite.h"

namespace simulator {

	class SimulateCommand : public Command
	{
	public:
		SimulateCommand() {};
		~SimulateCommand() {};

		// Inherited via Command
		string name() override
		{
			return this->commands.simulate;
		}
		void Execute(string params) override
		{
			string::size_type sz;
			auto str = Split(params, ' ').at(1);
			double time = stod(str, &sz);
			this->Log("\n...starting simulation...\n");
			this->Log("\n...simulation time: " + str + "...\n");
			this->global.Simulate(time, *this->_logger);			
		};

	};

}