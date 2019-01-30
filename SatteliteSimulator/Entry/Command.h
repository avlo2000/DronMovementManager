#pragma once
#include "CmdUtils.h"
#include "CmdList.h"
#include "GlbState.h"
#define COMMAND_DEF

namespace simulator {

#ifndef SIMULATOR_COMMANDER_DEF
	class Commander;
#endif
	class Command
	{
	protected:
		virtual string name() = 0;
		CmdList commands;
		GlbState global;
		ostream *_logger;
		void Log(std::string str)
		{
			*_logger << str;
		}
	public:
		virtual void Execute(string params) = 0;
		void SetLogger(ostream *logger)
		{
			_logger = logger;
		}
		bool Check(string cmd)
		{
			if (name().find(cmd) != string::npos)
				return true;
			else
				return false;
		}
	};
}

