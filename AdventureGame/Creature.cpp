#include "Creature.h"

Creature::Creature()
	:Thing()
	,health(0)
	,attack(0)
{
}

Creature::~Creature()
{
}

int Creature::GetAttack()
{
	return attack;
}

int Creature::GetHealth()
{
	return health;
}
