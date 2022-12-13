#include "Item.h"
#include <iostream>

Item::Item()
	:Thing()
{
	std::cout << "Item: " << name << " was created" << std::endl;
}

Item::Item(std::string newName, std::string newDescription)
	:Thing(newName, newDescription)
{
	std::cout << "Item: " << name << " was created using parameters" << std::endl;
}

Item::~Item()
{
	std::cout << "Item: " << name << " was destroyed" << std::endl;
}
