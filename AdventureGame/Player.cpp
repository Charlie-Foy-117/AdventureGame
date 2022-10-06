#include "Player.h"
#include <iostream>

void Player::PrintPlayer()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << "Health: " << health << std::endl
        << "Attack: " << attack << std::endl
        << "Weapon: " << weapon << std::endl
        << "Armour: " << armour << std::endl
        << " " << std::endl;
    std::cout << name << "'s Inventory:" << std::endl;
    for (size_t i = 0; i < inventory.size(); i++)
    {
        std::cout << inventory[i] << std::endl;
    }
    std::cout << " " << std::endl;
}

void Player::Go()
{

}
