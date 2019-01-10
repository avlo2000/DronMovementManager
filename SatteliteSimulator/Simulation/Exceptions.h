#pragma once
#include <exception>

class WrongPointTypeException : public std::exception
{
	const char * what() const throw () { return "No such type of point"; }
};

class NotImplementedException : public std::exception
{
	const char * what() const { return "Function not yet implemented"; }
};

class UnregisteredObjectException : public std::exception
{
	const char * what() const { return "Object for controler was not registered"; }
};