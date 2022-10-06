#pragma once
#include <string>
#include <vector>
class Area
{
public:
	//constructors

	//functions/methods
	void PrintArea();
	void Look();

	//variables
	std::string name;
	std::string description;
	std::vector<std::string> contents;
	std::vector<std::string> exits;
};

