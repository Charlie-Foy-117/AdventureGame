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
	void TakeDamage(int takenDamage);
	void DealDamage(Player* myPlayer);
	void LookAtMonster();

	//getter
	std::string GetName();
	bool GetAlive();

private:
	//variables
};

