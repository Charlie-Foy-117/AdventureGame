#pragma once
#include <string>
#include <vector>
class Player;

class Area
{
public:
	//constructors
	Area();
	Area(std::string newName, std::string newDescription, std::vector<Area*> newExits);
	~Area();


	//functions/methods
	void PrintArea();
	void Look();
	void Go(Player* currentArea, std::string target);
	void AddExit(Area* newExit);

	//getters
	std::string GetName();
	std::vector<Area*> GetExits();

private:
	//variables
	std::string name;
	std::string description;
	std::vector<Area*> exits;
};

