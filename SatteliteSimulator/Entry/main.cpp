#pragma once
#include"CmdResolver.h"
#include<iostream>
#include <string>

using namespace simulator;

int main()
{
	CmdResolver cmd(&cout);
	string input = "";
	while (input != "exit")
	{
		getline(std::cin, input);
		cmd.ExecuteAny(input);
	}
	return 0;
}