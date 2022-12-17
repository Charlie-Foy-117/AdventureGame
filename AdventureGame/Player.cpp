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
    Creature::Look();
    std::cout << "Current Area: " << currentArea->GetName() << std::endl
        << " " << std::endl;
    LookAtInventory();
        
}

void Player::LookAtInventory()
{
    std::cout << "Inventory: " << std::endl;
    if (inventory.size() >= 1)
    {
        for (size_t i = 0; i < inventory.size(); i++)
        {
            std::cout << inventory[i]->GetName() << std::endl;
        }
    }
    else
    {
        std::cout << "Empty" << std::endl;
    }
}

void Player::AddToInventory(Item* itemToAdd)
{
    inventory.push_back(itemToAdd);
}

void Player::RemoveFromInventory(Item* itemToUse)
{
    for (size_t i = 0; i < inventory.size(); i++)
    {
        if (inventory[i] == itemToUse)
        {
            inventory.erase(inventory.begin() + i);
        }
    }
}

Area* Player::GetCurrentArea()
{
    return currentArea;
}

bool Player::GetAlive()
{
    return health > 0;
}

std::vector<Item*> Player::GetInventory()
{
    return inventory;
}

void Player::SetCurrentArea(Area* newCurrentArea)
{
    currentArea = newCurrentArea;
}

