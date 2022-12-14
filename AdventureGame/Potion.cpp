#include "Potion.h"
#include "Player.h"

Potion::Potion()
	:Item()
	,heal(0)
{
	std::cout << "Potion: " << name << " was created" << std::endl;
}

Potion::Potion(std::string newName, std::string newDescription, int newHeal)
	:Item(newName, newDescription)
	,heal(newHeal)
{
	std::cout << "Potion: " << name << " was created using parameters" << std::endl;
}

Potion::~Potion()
{
	std::cout << "Potion: " << name << " was destroyed" << std::endl;
}

void Potion::UsePotion(Player* effectPlayer)
{
	effectPlayer->PotionEffectOnHealth(heal);
}

int Potion::GetHeal()
{
	return heal;
}
