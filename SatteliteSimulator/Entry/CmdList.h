#pragma once
#include<string>

#include <string>

namespace simulator {

	struct CmdList
	{
	public:
		const std::string help = "help";
		const std::string exit = "exit";

#pragma region Satellite commands
		const std::string createDefault = "add";//name of satellite as param
		const std::string loadSat = "add -load";//name of satellite and path to saved nn as params
		const std::string sats = "list";//outputs list of satallites
#pragma endregion

#pragma region Simulation commands
		const std::string simStep = "step ";//time as param	
		const std::string simulate = "simulate "; //time as param
		const std::string control = "control ";//name of satellite and 3D vector of rotation speeds as params
		const std::string powerToWheel = "pow ";//name of satellite number of wheel and work in Jouels as params
#pragma endregion
	};

}