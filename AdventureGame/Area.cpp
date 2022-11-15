#include "Area.h"
#include "Player.h"
#include <iostream>


Area::Area()
    :name(" ")
    , description(" ")
    , contents()
    , exits()
{
    std::cout << "Area Constructed" << std::endl;
}

Area::Area(std::string newName, std::string newDescription, std::vector<std::string> newContents, std::vector<Area*> newExits)
    :name(newName)
    ,description(newDescription)
    ,contents(newContents)
    ,exits(newExits)
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
        << "Contents: " << std::endl;
    for (size_t i = 0; i < contents.size(); i++)
    {
        std::cout << contents[i] << std::endl;
    }
    std::cout << " " << std::endl;
    std::cout << "Exits: " << std::endl;
    for (size_t i = 0; i < exits.size(); i++)
    {
        std::cout << exits[i] << std::endl;
    }
    std::cout << " " << std::endl;
}

void Area::Look()
{
	std::cout << description << std::endl
        << " " << std::endl
        << "Contents: " << std::endl;
    for (size_t i = 0; i < contents.size(); i++)
    {
        std::cout << contents[i] << std::endl;
    }
    std::cout << " " << std::endl;
	std::cout << "Pathways: " << std::endl;
	for (size_t i = 0; i < exits.size(); ++i)
	{
		std::cout << exits[i]->name << std::endl;
	}
    std::cout << " " << std::endl;
}

void Area::Go(Player* newCurrentArea, std::string target)
{
    bool answer = false;
    for (size_t i = 0; i < newCurrentArea->currentArea->exits.size(); i++)
    {
        if (newCurrentArea->currentArea->exits[i]->name == target)
        {
            newCurrentArea->currentArea = newCurrentArea->currentArea->exits[i];
            std::cout << "You are now in the " << newCurrentArea->currentArea->name << std::endl;
            answer = true;
        }
        
    }
    if (answer == false)
    {
        std::cout << "Invalid Choice, Try again" << std::endl;
    }
}
