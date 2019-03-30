#pragma once
#include "Command.h"
#include "NeuralConfig.h"

namespace simulator {

	class PowerToWheelCommand :
		public Command
	{
	public:
		PowerToWheelCommand() {};
		~PowerToWheelCommand() {};

		// Inherited via Command
		virtual string name() override
		{
			return this->commands.powerToWheel;
		};
		virtual void Execute(string params) override
		{
			auto parse = Split(params, ' ');

			string name = parse[1];
			string::size_type sz;
			int index = stoi(parse[2], &sz);
			double power = stod(parse[3], &sz);

			this->Log("\n...powering the wheel...\n");
			auto obj = this->global.GetController(name)->GetRegistration();
			auto copy = *obj;
			auto copyMax = *CreateSatellite("copy");
			auto copyMin = *CreateSatellite("copy");

			copy.EnergyToReactionWheel(index - 1, power);
			copyMax.EnergyToReactionWheel(index - 1, RANGEEND);
			copyMin.EnergyToReactionWheel(index - 1, RANGESTART);

			if ((copy.GetRotationSpeeds().x() > copyMax.GetRotationSpeeds().x() 
					|| copy.GetRotationSpeeds().y() > copyMax.GetRotationSpeeds().y()
					|| copy.GetRotationSpeeds().z() > copyMax.GetRotationSpeeds().z())
				|| (copy.GetRotationSpeeds().x() < copyMin.GetRotationSpeeds().x()
					|| copy.GetRotationSpeeds().y() < copyMin.GetRotationSpeeds().y()
					|| copy.GetRotationSpeeds().z() < copyMin.GetRotationSpeeds().z()))
			{
				this->Log("\nPOWER IN THIS RANGE IS NOT ALLOWD FOR THIS SATELLITE\n\n");
				return;
			}
			obj->EnergyToReactionWheel(index - 1, power);

			this->Log("\n...power of reaction wheel was changed...\n");
		};
	};

}
