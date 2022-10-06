#include "Area.h"
#include <iostream>


void Area::PrintArea()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << "Contents: " << std::endl;
    for (size_t i = 0; i < contents.size(); i++)
    {
        std::cout << contents[i] << std::endl;
    }
    std::cout << "Exits: " << std::endl;
    for (size_t i = 0; i < exits.size(); i++)
    {
        std::cout << exits[i] << std::endl;
    }
    std::cout << " " << std::endl;
}

void Area::Look()
{
	std::cout << description << std::endl;

	std::cout << "Pathways: " << std::endl;
	for (size_t i = 0; i < exits.size(); ++i)
	{
		std::cout << exits[i] << std::endl;
	}
}
