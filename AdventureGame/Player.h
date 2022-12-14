#pragma once
#include <string>
#include <vector>
#include "Creature.h"
class Item;
class Area;

class Player : public Creature
{
public:
	//constructors
	Player();
	Player(std::string newName, std::string newDescription, int newHealth, int newAttack, Area* newCurrentArea, std::vector<Item*> newInventory);
	~Player();

	//functions/methods
	void LookAtSelf();
	void LookAtInventory();
	void AddToInventory(Item* itemToAdd);

	//getters
	Area* GetCurrentArea();
	bool GetAlive();

	//setters
	void SetCurrentArea(Area* newCurrentArea);

protected:

	//variables
	Area* currentArea;
	std::vector<Item*> inventory;
};

