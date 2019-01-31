#pragma once
#include<string>

namespace simulator {

	struct CmdList
	{
	public:
		const std::string help = "help";
		const std::string exit = "exit";
		const std::string addSat = "add sat ";//name of satellite as param
		const std::string simStep = "set step ";//time as param
		const std::string createDefault = "add -d sat ";//name of satellite as param
		const std::string simulate = "simulate "; //time as param
		const std::string control = "control ";//name of satellite and 3D vector of rotation speeds as params
	};

}