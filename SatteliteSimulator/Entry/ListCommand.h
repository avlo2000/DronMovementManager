#pragma once
#pragma once
#include "Command.h"
#include <string>

using namespace std;

namespace simulator {

	class ListCommand : public Command
	{
	public:
		ListCommand() {};
		~ListCommand() {};

		// Inherited via Command
		string name() override
		{
			return this->commands.sats;
		};
		void Execute(string params) override
		{
			auto sats = this->global.Names();
			for (auto name : sats)
				Log(name + "\n");
			Log("\n");
		};

	};

}