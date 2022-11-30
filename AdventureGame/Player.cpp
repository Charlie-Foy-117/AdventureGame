#include "Player.h"
#include "Area.h"
#include <iostream>

Player::Player()
    :Creature()
    ,currentArea(nullptr)
{
    std::cout << "Player: " << name << " was created" << std::endl;
}

Player::Player(std::string newName, std::string newDescription, int newHealth, int newAttack, Area* newCurrentArea)
    :Creature(newName, newDescription, newHealth, newAttack)
    ,currentArea(newCurrentArea)
{
    std::cout << "Player: " << name <<" was created using parameters" << std::endl;
}

Player::~Player()
{
    std::cout << "Player: " << name << " was destoryed" << std::endl;
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

