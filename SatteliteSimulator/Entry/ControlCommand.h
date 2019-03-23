#pragma once
#include "Command.h"
#include "Constants.h"

namespace simulator {

	class ControlCommand :
		public Command
	{
	public:
		ControlCommand() {};
		~ControlCommand() {};

		// Inherited via Command
		string name() override
		{
			return this->commands.control;
		};
		void Execute(string params) override
		{
			auto parse = Split(params, ' ');
			string name = parse[1];
			string::size_type sz;
			double xRot = stod(parse[2], &sz);
			double yRot = stod(parse[3], &sz);
			double zRot = stod(parse[4], &sz);

			if (xRot > ENERGY_THRESHOLD || yRot > ENERGY_THRESHOLD || zRot > ENERGY_THRESHOLD)
			{
				this->Log("\nINCORRECT SPEEDS\n(rotation speeds must in range[" 
					+ std::to_string(-ENERGY_THRESHOLD) + ".."+ std::to_string(ENERGY_THRESHOLD) + "])\n\n");
				return;
			}

			Vector3d vec(xRot, yRot, zRot);
			global.Control(vec, name);
			this->Log("\n...controller has worked out...\n");
		};
	};

}