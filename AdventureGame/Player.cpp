#include "Player.h"
#include "Area.h"
#include <iostream>

Player::Player()
    :Creature()
    ,currentArea(nullptr)
{
    std::cout << "Player Constructed" << std::endl;
}

Player::Player(std::string newName, std::string newDescription, int newHealth, int newAttack, Area* newCurrentArea)
    :Creature()
    ,currentArea(newCurrentArea)
{
    std::cout << "Player Constructed with Parameters" << std::endl;
}

Player::~Player()
{
    std::cout << "Player Destoryed" << std::endl;
}

void Player::LookAtSelf()
{
    std::cout << "Name: " << name << std::endl
        << "Description: " << description << std::endl
        << "Health: " << health << std::endl
        << "Attack: " << attack << std::endl
        << "Current Area: " << currentArea->GetName() << std::endl
        << " " << std::endl;
}

void Player::TakeDamage(int takenDamage)
{
    health -= takenDamage;
    std::cout << " " << std::endl
        << "Player's health is now " << health << std::endl;
}

std::string Player::GetName()
{
    return name;
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

