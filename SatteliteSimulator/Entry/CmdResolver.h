#pragma once
#include "Command.h"
#include"AddDefaultSatCommand.h"
#include"HelpCommand.h"
#include "SetTimeStepCommand.h"
#include "SimulateCommand.h"
#include "ControlCommand.h"
#include "LoadCommand.h"
#include "PowerToWheelCommand.h"
#include "ListCommand.h"

namespace simulator {

	class CmdResolver
	{
	private:
		vector<Command*> _commands;

	public:
		CmdResolver(ostream *logger)
		{
			_commands.push_back(new LoadCommand());
			_commands.push_back(new AddDefaultSatCommand());
			_commands.push_back(new HelpCommand());
			_commands.push_back(new SetTimeStepCommand());
			_commands.push_back(new SimulateCommand());
			_commands.push_back(new ControlCommand());		
			_commands.push_back(new PowerToWheelCommand());
			_commands.push_back(new ListCommand());

			for (int i = 0; i < _commands.size(); i++)
				_commands[i]->SetLogger(logger);
		};

		void ExecuteAny(string cmd)
		{
			for (int i = 0; i < _commands.size(); i++)
				if (_commands[i]->Check(cmd))
				{
					_commands[i]->Execute(cmd);
					return;
				}
		};
		~CmdResolver() {};
	};

}

