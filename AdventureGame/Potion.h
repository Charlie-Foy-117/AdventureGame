#pragma once
#include "Item.h"
class Player;

class Potion : public Item
{
public:

	Potion();
	Potion(std::string newName, std::string newDescription, int newHeal);
	~Potion();


	int GetHeal();
private:

	int heal;
};

