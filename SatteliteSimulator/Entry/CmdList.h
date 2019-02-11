#pragma once
#include<string>

namespace simulator {

	struct CmdList
	{
	public:
		const string help = "help";
		const string exit = "exit";

#pragma region Satellite commands
		const string addSat = "add sat ";//name of satellite as param
		const string createDefault = "add -d sat ";//name of satellite as param
		const string loadSat = "add -d -load sat ";//name of satellite and path to saved nn as params
#pragma endregion

#pragma region Simulation commands
		const string simStep = "set step ";//time as param	
		const string simulate = "simulate "; //time as param
		const string control = "control ";//name of satellite and 3D vector of rotation speeds as params
		const string powerToWheel = "pow to sat";//name of satellite number of wheel and work in Jouels as params
#pragma endregion
	};

}