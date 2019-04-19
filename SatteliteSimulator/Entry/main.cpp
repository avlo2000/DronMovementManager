#pragma once
#include"CmdResolver.h"
#include<iostream>
#include <string>

using namespace simulator;

int main()
{
	cout << "Welcome to satellite simulator. Type \"help\" to get list of commands\n\n";
	CmdResolver cmd(&cout);
	string input = "";
	while (input != "exit")
	{
		cout << ">>>";
		getline(std::cin, input);

		try
		{
			cmd.ExecuteAny(input);
		}
		catch(exception)
		{
			cout << "Incorrect input" << endl << endl;
		}
	}
	return 0;
}