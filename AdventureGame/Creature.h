#pragma once
#include "Thing.h"
class Item;
class Potion;

class Creature : public Thing
{
public: 
	Creature();
	Creature(std::string newName, std::string newDescription, int newHealth, int newAttack);
	~Creature();

	void Look();
	void TakeDamage(int takenDamage);
	void DealDamage(int dealtDamage, Creature* target);

	int GetAttack();
	int GetHealth();

	void PotionEffect(Potion* potion);
	virtual void Use(std::string target, Item* itemToUse, Creature* myCreature);

protected:

	int health;
	int attack;
};

