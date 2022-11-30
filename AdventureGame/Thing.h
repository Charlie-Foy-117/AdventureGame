#pragma once
#include <iostream>
class Thing
{
public:

	Thing();
	Thing(std::string newName, std::string newDescription);
	~Thing();

	void Look();

	std::string GetName();

protected:

	std::string name;
	std::string description;
};

