#include "Area.h"
#include "Player.h"
#include <iostream>


Area::Area()
    :Thing()
    ,exits()
    ,monster(nullptr)
{
    std::cout << "Area Constructed" << std::endl;
}

Area::Area(std::string newName, std::string newDescription, std::vector<Area*> newExits, Monster* newMonster)
    :Thing(newName, newDescription)
    ,exits(newExits)
    ,monster(newMonster)
{
    std::cout << "Area Constructed with Parameters" << std::endl;
}

Area::~Area()
{
    std::cout << "Area Destoryed" << std::endl;
}

void Area::PrintArea()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << " " << std::endl
        << "Exits: " << std::endl;
    for (size_t i = 0; i < exits.size(); i++)
    {
        std::cout << exits[i] << std::endl;
    }
    std::cout << " " << std::endl;
}

void Area::Look()
{
    Thing::Look();
	std::cout << " " << std::endl
	    << "Pathways: " << std::endl;
	for (size_t i = 0; i < exits.size(); ++i)
	{
		std::cout << exits[i]->name << std::endl;
	}
    std::cout << " " << std::endl;
}

void Area::Go(Player* newCurrentArea, std::string target)
{
    bool answer = false;
    for (size_t i = 0; i < newCurrentArea->GetCurrentArea()->exits.size(); i++)
    {
        if (newCurrentArea->GetCurrentArea()->exits[i]->name == target)
        {
            newCurrentArea->SetCurrentArea(newCurrentArea->GetCurrentArea()->exits[i]);
            std::cout << "You are now in the " << newCurrentArea->GetCurrentArea()->name << std::endl;
            answer = true;
        }
        
    }
    if (answer == false)
    {
        std::cout << "Invalid Choice, Try again" << std::endl;
    }
}

void Area::AddExit(Area* newExit)
{
    exits.push_back(newExit);
}

void Area::SetMonster(Monster* newMonster)
{
    monster = newMonster;
}

std::vector<Area*> Area::GetExits()
{
    return exits;
}

Monster* Area::GetMonster()
{
    return monster;
}
