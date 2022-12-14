#include "Monster.h"
#include "Player.h"
#include <iostream>

Monster::Monster()
    :Creature()
{
    std::cout << "Monster: " << name << " was created" << std::endl;
}

Monster::Monster(std::string newName, std::string newDescription, int newAttack, int newHealth)
    :Creature(newName, newDescription, newHealth, newAttack)
{
    std::cout << "Monster: " << name << " was created using parameters" << std::endl;
}

Monster::~Monster()
{
    std::cout << "Monster: " << name << " was destroyed" << std::endl;
}


void Monster::DealDamage(Player* myPlayer)
{
    if (health <= 0)
    {
        std::cout << "The monster is already dead, stop poking it" << std::endl;
        return;
    }
    std::cout << "You attack the monster" << std::endl;
    int playerDealtDamage = myPlayer->GetAttack();
    std::cout << "You deal " << playerDealtDamage << " damage" << std::endl;
    health -= playerDealtDamage;
    if (health <= 0)
    {
        std::cout << "You killed the monster" << std::endl
            << " " << std::endl;
    }
    else
    {
        std::cout << "The monster still stands and attacks you" << std::endl
            << "The monster deals " << attack << " damage to you" << std::endl;
        myPlayer->TakeDamage(attack);
        std::cout << name << " health is: " << health << std::endl;
    }
}

void Monster::LookAtMonster()
{
    std::cout << "You look at the monster: " << name << std::endl;
    std::cout << description << std::endl;
    if (health <= 0)
    {
        std::cout << "Monster: " << name << " is dead" << std::endl;
    }
    else
    {
        std::cout << "The monsters health is: " << health << std::endl
            << "The monsters damage is: " << attack << std::endl;
    }
}

bool Monster::GetAlive()
{
    return health > 0;
}
