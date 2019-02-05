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
			Satellite* sat = CreateSatellite(Split(params, ' ').at(4));
			global.AddObject(*sat);

			this->Log("\n...satellite with name " + sat->GetName() + " has been added to the simulation...\n");
			this->Log("\n...creating neural contoller for " + sat->GetName() + " satellite...\n");
			Controller *cntr = new Controller();
			cntr->RegisterObject(sat);
			this->Log("\n...loading neural network for " + sat->GetName() + " satellite...\n");
			cntr->LoadNetwork("parameters.txt"/*Split(params, ' ').at(5)*/);
			global.AddController(cntr);
			this->Log("\n...neural network has been successfully loaded...\n");
		};
	};

}