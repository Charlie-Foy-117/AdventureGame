#pragma once
#include <string>
#include <vector>
class Player
{
public:
	std::string name;
	std::string description;
	int health;
	int attack;
	std::string weapon;
	std::string armour;
	std::vector<std::string> inventory;
};

