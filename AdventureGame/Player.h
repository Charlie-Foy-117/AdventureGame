#pragma once
#include <string>
#include <vector>
class Player
{
public:
	//constructors

	//functions/methods
	void PrintPlayer();
	void Go();

	//variables
	std::string name;
	std::string description;
	int health = 0;
	int attack = 0;
	std::string weapon;
	std::string armour;
	std::vector<std::string> inventory;
};

