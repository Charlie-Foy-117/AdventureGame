#include "Creature.h"
#include "Potion.h"
#include "Item.h"
#include "Player.h"

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
}

void Creature::DealDamage(int dealtDamage, Creature* target)
{
	if (target->health <= 0 )
	{
		std::cout << target->name << " is already dead, stop poking it" << std::endl;
		return;
	}
	target->TakeDamage(dealtDamage);
	if (target->health > 0)
	{
		std::cout << target->name << " health is now: " << target->health << std::endl;
		if (target->name != name)
		{
			this->TakeDamage(target->attack);
			std::cout << name << " health is now: " << health << std::endl;
		}
	}
	else
	{
		std::cout << target->name << " is now dead, congrats" << std::endl
			<< name << " health is still " << health << std::endl;
		return;
	}
}

int Creature::GetAttack()
{
	return attack;
}

int Creature::GetHealth()
{
	return health;
}

void Creature::PotionEffect(Potion* potion)
{
	if (potion->GetName() == "Small_Health_Potion")
	{
		health += potion->GetHeal();
		std::cout << this->name << " is now: " << this->health << std::endl;
	}
	
}

void Creature::Use(std::string target, Item* itemToUse, Creature* myCreature)
{
	if (target == "self")
	{
		if (itemToUse->GetName() == "Small_Health_Potion")
		{
			Potion* potionToUse = dynamic_cast<Potion*>(itemToUse);
			myCreature->PotionEffect(potionToUse);
			Player* myPlayer = dynamic_cast<Player*>(this);
			myPlayer->RemoveFromInventory(itemToUse);
		}
	}
	else if (target == "monster")
	{
		if (itemToUse->GetName() == "Small_Health_Potion")
		{
			Potion* potionToUse = dynamic_cast<Potion*>(itemToUse);
			myCreature->PotionEffect(potionToUse);
		}
	}
	else
	{
		std::cout << "Invalid target" << std::endl;
	}
}
