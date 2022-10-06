#include "Monster.h"
#include <iostream>

void Monster::PrintMonster()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << "Health: " << health << std::endl
        << "Attack: " << attack << std::endl
        << " " << std::endl;
}
