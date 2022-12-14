#pragma once
#include <string>
#include <vector>
#include "Thing.h"
class Monster;
class Player;
class Item;

class Area : public Thing
{
public:
	//constructors
	Area();
	Area(std::string newName, std::string newDescription, std::vector<Area*> newExits,std::vector<Item*> newItemContents, Monster* newMonster);
	~Area();


	//functions/methods
	void PrintArea();
	void Look();
	void LookAtContents();
	void Go(Player* currentArea, std::string target);
	void AddExit(Area* newExit);
	void AddItemContent(Item* newItem);
	void PickUpItem(Item* itemToPickup);

	//setters
	void SetMonster(Monster* newMonster);

	//getters
	std::vector<Area*> GetExits();
	Monster* GetMonster();
	std::vector<Item*> GetItemContents();

private:
	//variables
	std::vector<Area*> exits;
	std::vector<Item*> itemContents;
	Monster* monster;
};

