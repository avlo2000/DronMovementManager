#pragma once
#include "Command.h"
#include <string>

using namespace std;

namespace simulator {

	class HelpCommand : public Command
	{
	public:
		HelpCommand() {};
		~HelpCommand() {};

		// Inherited via Command
		string name() override
		{
			return this->commands.help;
		};
		void Execute(string params) override
		{
			this->Log(this->commands.addSat + 
				"| adds new unconfigured satellite\nname of satellite as param(NOT IMPLEMENTED YET. USE DEFAULT SATELLITE)\n\n");
			this->Log(this->commands.createDefault + 
				"| adds satellite with default configuration(watch documantation) and trains controler for it\nname of satellite as param\n\n");
			this->Log(this->commands.loadSat + 
				"| adds satellite with default configuration(watch documantation) with already trained controller\nname of satellite as param\n\n");
			this->Log(this->commands.simStep + 
				"| sets time step(simulation interval)\n double as param\n\n");
			this->Log(this->commands.control + 
				"| control rotation speeds of satellite\nname of satellite and 3D vector as params\n\n");
			this->Log(this->commands.simulate + 
				"| simulates during setted time\n double(time) as param\n\n");
			this->Log(this->commands.exit + 
				"| exit the simulator\n");
		};
		
	};

}