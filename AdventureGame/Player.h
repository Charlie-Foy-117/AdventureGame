#pragma once
#include <string>
#include <vector>
class Area;

class Player
{
public:
	//constructors
	Player();
	Player(std::string newName, std::string newDescription, int newHealth, int newAttack, Area* newCurrentArea);
	~Player();

	//functions/methods
	void PrintPlayer();

	//getters
	std::string GetName();
	Area* GetCurrentArea();

	//setters
	void SetCurrentArea(Area* newCurrentArea);

private:

	//variables
	std::string name;
	std::string description;
	int health = 0;
	int attack = 0;
	Area* currentArea;
};

