#pragma once
#include <string>
#include "Creature.h"

class Player;

class Monster : public Creature
{
public:

	//constructors/destructors
	Monster();
	Monster(std::string newName, std::string newDescription, int newAttack, int newHealth);
	~Monster();

	//functions
	void PrintMonster();
	void DealDamage(Player* myPlayer);
	void LookAtMonster();

	//getter
	bool GetAlive();

private:
	//variables
};

