#pragma once
#include "Command.h"
#include "DefaultSatellite.h"

namespace simulator {

	class LoadCommand :
		public Command
	{
	public:
		LoadCommand() {};
		~LoadCommand() {};

		// Inherited via Command
		virtual string name() override
		{
			return this->commands.loadSat;
		};
		virtual void Execute(string params) override
		{
			string name;
			if (Split(params, ' ').size() == 3)
				name = Split(params, ' ').at(2);
			else
				name = "sat" + to_string(this->global.NumOfSats() + 1);
			Satellite* sat = CreateSatellite(name);
			global.AddObject(*sat);

			this->Log("\n...satellite with name " + sat->GetName() + " has been added to the simulation...\n");
			this->Log("\n...creating neural contoller for " + sat->GetName() + " satellite...\n");
			Controller *cntr = new Controller();
			cntr->RegisterObject(sat);
			this->Log("\n...loading neural network for " + sat->GetName() + " satellite...\n");
			cntr->LoadNetwork(sat->GetName() + "_nnbiases.txt");
			global.AddController(cntr);
			this->Log("\n...neural network has been successfully loaded...\n");
		};
	};

}