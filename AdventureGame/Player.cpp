#include "Player.h"
#include "Area.h"
#include "Item.h"
#include <iostream>

Player::Player()
    :Creature()
    ,currentArea(nullptr)
    ,inventory()
{
    std::cout << "Player: " << name << " was created" << std::endl;
}

Player::Player(std::string newName, std::string newDescription, int newHealth, int newAttack, Area* newCurrentArea, std::vector<Item*> newInventory)
    :Creature(newName, newDescription, newHealth, newAttack)
    ,currentArea(newCurrentArea)
    ,inventory(newInventory)
{
    std::cout << "Player: " << name <<" was created using parameters" << std::endl;
}

Player::~Player()
{
    std::cout << "Player: " << name << " was destroyed" << std::endl;
}

void Player::LookAtSelf()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << "Health: " << health << std::endl
        << "Attack: " << attack << std::endl
        << "Current Area: " << currentArea->GetName() << std::endl
        << " " << std::endl;
    LookAtInventory();
        
}

void Player::LookAtInventory()
{
    std::cout << "Inventory: " << std::endl;
    for (size_t i = 0; i < inventory.size(); i++)
    {
        std::cout << "  " << inventory[i]->GetName() << std::endl;
    }
}

void Player::AddToInventory(Item* itemToAdd)
{
    inventory.push_back(itemToAdd);
}

Area* Player::GetCurrentArea()
{
    return currentArea;
}

bool Player::GetAlive()
{
    return health > 0;
}

void Player::SetCurrentArea(Area* newCurrentArea)
{
    currentArea = newCurrentArea;
}

