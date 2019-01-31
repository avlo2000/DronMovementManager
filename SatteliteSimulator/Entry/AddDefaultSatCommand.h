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
			Satellite* sat = CreateSatellite(Split(params, ' ').at(3));
			global.AddObject(*sat);
			this->Log("\n...satellite with name " + sat->GetName() + " has been added to the simulation...\n");
			this->Log("\n...creating neural contoller for " + sat->GetName() + " satellite...\n");
			Controller cntr;
			cntr.RegisterObject(sat);
			this->Log("\n...warming up the controller...\n");
			cntr.Train();
			global.AddController(cntr);
			this->Log("\n...controller has been successfully warmed up...\n");
		};

	};

}
