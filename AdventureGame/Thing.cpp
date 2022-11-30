#include "Thing.h"

Thing::Thing()
	:name("")
	,description("")
{
	std::cout << "Thing: " << name << " was created" << std::endl;
}

Thing::Thing(std::string newName, std::string newDescription)
	:name(newName)
	,description(newDescription)
{
	std::cout << "Thing: " << name << " was created using parameters" << std::endl;
}

Thing::~Thing()
{
	std::cout << "Thing: " << name << " was destroyed" << std::endl;
}

void Thing::Look()
{
	std::cout << "Name: " << name << std::endl
		<< "Description: " << description << std::endl;
}

std::string Thing::GetName()
{
	return name;
}
