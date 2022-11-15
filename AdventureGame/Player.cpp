#include "Player.h"
#include "Area.h"
#include <iostream>

Player::Player()
    :name(" ")
    , description(" ")
    , health(0)
    , attack(0)
    , weapon(" ")
    , armour(" ")
    , currentArea(nullptr)
{
    std::cout << "Player Constructed" << std::endl;
}

Player::Player(std::string newName, std::string newDescription, int newHealth, int newAttack, std::string newWeapon, std::string newArmour, Area* newCurrentArea)
    :name(newName)
    ,description(newDescription)
    ,health(newHealth)
    ,attack(newAttack)
    ,weapon(newWeapon)
    ,armour(newArmour)
    ,currentArea(newCurrentArea)
{
    std::cout << "Player Constructed with Parameters" << std::endl;
}

Player::~Player()
{
    std::cout << "Player Destoryed" << std::endl;
}

void Player::PrintPlayer()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << "Health: " << health << std::endl
        << "Attack: " << attack << std::endl
        << "Weapon: " << weapon << std::endl
        << "Armour: " << armour << std::endl
        << "Current Area: " << currentArea << std::endl
        << " " << std::endl;
    std::cout << name << "'s Inventory:" << std::endl;
    for (size_t i = 0; i < inventory.size(); i++)
    {
        std::cout << inventory[i] << std::endl;
    }
    std::cout << " " << std::endl;
}
