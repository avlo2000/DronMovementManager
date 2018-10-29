#pragma once
#include <exception>

class WrongPointTypeException : public std::exception
{
	const char * what() const throw ()
	{
		return "No such type of point";
	}
};