#pragma once
#include <exception>

class WrongPointTypeException : public std::exception
{
	const char * what() const throw () { return "No such type of point"; }
};

class NotImplementedException : public std::exception
{
	const char * what() const throw () { return "Function not yet implemented"; }
};

class UnregisteredObjectException : public std::exception
{
	const char * what() const throw() { return "Object for controler was not registered"; }
};
