#pragma once
#include "Thing.h"

class Creature : public Thing
{
public: 
	Creature();
	Creature(std::string newName, std::string newDescription, int newHealth, int newAttack);
	~Creature();

	void Look();
	void TakeDamage(int takenDamage);

	int GetAttack();
	int GetHealth();

protected:

	int health;
	int attack;
};

