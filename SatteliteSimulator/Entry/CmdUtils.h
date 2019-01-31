#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>

using namespace std;

namespace simulator {



	inline string startsWith(const string &str, const string &prefix) {
		smatch match;
		regex_search(str, match, regex("^" + prefix));
		return match.suffix();
	}

	inline const vector<string> Split(const string& s, const char& c)
	{
		string buff{ "" };
		vector<string> v;

		for (auto n : s)
		{
			if (n != c) buff += n; else
				if (n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "") v.push_back(buff);

		return v;
	}

}