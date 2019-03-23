#pragma once
#include "Command.h"
#include "DefaultSatellite.h"

namespace simulator {

	class AddDefaultSatCommand : public Command
	{
	public:
		AddDefaultSatCommand() {};
		~AddDefaultSatCommand() {};

		// Inherited via Command		
		string name() override
		{
			return this->commands.createDefault;
		}
		void Execute(std::string params) override
		{
			string name;
			if (Split(params, ' ').size() == 2)
				name = Split(params, ' ').at(1);
			else
				name = "sat" + to_string(this->global.NumOfSats() + 1);
			Satellite* sat = CreateSatellite(name);

			global.AddObject(*sat);

			this->Log("\n...satellite with name " + sat->GetName() + " has been added to the simulation...\n");
			this->Log("\n...creating neural contoller for " + sat->GetName() + " satellite...\n");

			Controller *cntr = new Controller();
			cntr->RegisterObject(sat);

			this->Log("\n...warming up the controller...\n");
			cntr->Train(sat->GetName() + "_nnbiases.txt");

			global.AddController(cntr);
			this->Log("\n...controller has been successfully warmed up...\n");
		};

	};

}
