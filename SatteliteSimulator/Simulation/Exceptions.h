#pragma once
#include <exception>

class WrongPointTypeException : public std::exception
{
	const char * what() const throw ()
	{
		return "No such type of point";
	}
};
class NotImplementedException : public std::logic_error {
		virtual char const * what() const { return "Function not yet implemented."; }
};