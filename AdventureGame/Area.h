#pragma once
#include <string>
#include <vector>
#include "Thing.h"
class Monster;
class Player;

class Area : public Thing
{
public:
	//constructors
	Area();
	Area(std::string newName, std::string newDescription, std::vector<Area*> newExits, Monster* newMonster);
	~Area();


	//functions/methods
	void PrintArea();
	void Look();
	void Go(Player* currentArea, std::string target);
	void AddExit(Area* newExit);

	//setters
	void SetMonster(Monster* newMonster);

	//getters
	std::vector<Area*> GetExits();
	Monster* GetMonster();

private:
	//variables
	std::vector<Area*> exits;
	Monster* monster;
};

