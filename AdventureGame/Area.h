#pragma once
#include <string>
#include <vector>
class Player;

class Area
{
public:
	//constructors
	Area();
	Area(std::string newName, std::string newDescription, std::vector<std::string> newContents, std::vector<Area*> newExits);
	~Area();


	//functions/methods
	void PrintArea();
	void Look();
	void Go(Player* currentArea, std::string target);

	//variables
	std::string name;
	std::string description;
	std::vector<std::string> contents;
	std::vector<Area*> exits;
};

