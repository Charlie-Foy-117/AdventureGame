#pragma once
#include "Thing.h"

class Creature : public Thing
{
public: 
	Creature();
	~Creature();

	int GetAttack();
	int GetHealth();

protected:

	int health;
	int attack;
};

