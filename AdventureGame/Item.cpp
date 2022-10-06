#include "Item.h"
#include <iostream>

void Item::PrintItem()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << " " << std::endl;
}
