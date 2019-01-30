#pragma once
#include "Command.h"
#include"AddDefaultSatCommand.h"
#include"HelpCommand.h"

namespace simulator {

	class CmdResolver
	{
	private:
		vector<Command*> _commands;

	public:
		CmdResolver(ostream *logger)
		{
			_commands.push_back(new AddDefaultSatCommand());
			_commands.push_back(new HelpCommand());
			for (int i = 0; i < _commands.size(); i++)
				_commands[i]->SetLogger(logger);
		};

		void ExecuteAny(string cmd)
		{
			for (int i = 0; i < _commands.size(); i++)
				if (_commands[i]->Check(cmd))
					_commands[i]->Execute(cmd);
		};
		~CmdResolver() {};
	};

}

