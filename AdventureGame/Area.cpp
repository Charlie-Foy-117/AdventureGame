#include "Area.h"
#include <iostream>


Area::Area()
    :name(" ")
    , description(" ")
    , contents()
    , exits()
{
    std::cout << "Area Constructed" << std::endl;
}

Area::Area(std::string newName, std::string newDescription, std::vector<std::string> newContents, std::vector<std::string> newExits)
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
		std::cout << exits[i] << std::endl;
	}
    std::cout << " " << std::endl;
}
