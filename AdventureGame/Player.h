#pragma once
#include <string>
#include <vector>
#include "Creature.h"
class Area;

class Player : public Creature
{
public:
	//constructors
	Player();
	Player(std::string newName, std::string newDescription, int newHealth, int newAttack, Area* newCurrentArea);
	~Player();

	//functions/methods
	void LookAtSelf();

	//getters
	Area* GetCurrentArea();
	bool GetAlive();

	//setters
	void SetCurrentArea(Area* newCurrentArea);

private:

	//variables
	Area* currentArea;
};

