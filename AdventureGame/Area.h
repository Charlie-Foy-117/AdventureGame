#pragma once
#include <string>
#include <vector>
class Area
{
public:
	//constructors
	Area();
	Area(std::string newName, std::string newDescription, std::vector<std::string> newContents, std::vector<std::string> newExits);
	~Area();


	//functions/methods
	void PrintArea();
	void Look();

	//variables
	std::string name;
	std::string description;
	std::vector<std::string> contents;
	std::vector<std::string> exits;
};

