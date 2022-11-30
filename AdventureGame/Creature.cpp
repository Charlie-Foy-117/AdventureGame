#include "Creature.h"

Creature::Creature()
	:Thing()
	,health(0)
	,attack(0)
{
	std::cout << "Creature: " << name << " was created" << std::endl;
}

Creature::Creature(std::string newName, std::string newDescription, int newHealth, int newAttack)
	:Thing(newName, newDescription)
	,health(newHealth)
	,attack(newAttack)
{
	std::cout << "Creature: " << name << " was created using parameters" << std::endl;
}

Creature::~Creature()
{
	std::cout << "Creature: " << name << " was destroyed" << std::endl;
}

void Creature::Look()
{
	Thing::Look();
	std::cout << "Health: " << health << std::endl
		<< "Attack: " << attack << std::endl;
}

void Creature::TakeDamage(int takenDamage)
{
	health -= takenDamage;
	std::cout << " " << std::endl
		<< name	<< " health is now " << health << std::endl;
}

int Creature::GetAttack()
{
	return attack;
}

int Creature::GetHealth()
{
	return health;
}
