#pragma once
#include <string>
#include <vector>
class Player
{
public:
	//constructors
	Player();
	Player(std::string newName, std::string newDescription, int newHealth, int newAttack, std::string newWeapon, std::string newArmour, std::string newCurrentArea);
	~Player();

	//functions/methods
	void PrintPlayer();
	void Go(std::string newCurrentArea);

	//variables
	std::string name;
	std::string description;
	int health = 0;
	int attack = 0;
	std::string weapon;
	std::string armour;
	std::string currentArea;
	std::vector<std::string> inventory;
};

