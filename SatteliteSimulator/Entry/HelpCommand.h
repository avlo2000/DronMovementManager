#pragma once
#include "Command.h"
#include <string>
using namespace std;
namespace simulator {

	class HelpCommand : public Command
	{
	public:
		HelpCommand() {};
		virtual HelpCommand* create() { return new HelpCommand; }

		std::string name() override
		{
			return this->commands.help;
		};
		void Execute(std::string params) override
		{
			this->Log(this->commands.addSat + "- adds new unconfigured satellite\nname of satellite as param\n\n");
			this->Log(this->commands.addController + "- adds controller and train it\nname of satellite as param\n\n");
			this->Log(this->commands.createDefault + "- adds satellite with default configuration(watch documantation)\nname of satellite as param\n\n");
			this->Log(this->commands.simStep + "- sets time step(simulation interval)\n double as param\n\n");
			this->Log(this->commands.control + "- control rotation speeds of satellite\nname of satellite and 3D vector as params\n\n");
			this->Log(this->commands.simulate + "- simulates during setted time\n double(time) as param\n\n");
			this->Log(this->commands.exit + "- exit the simulator");
		};
		~HelpCommand() {};
	};

}