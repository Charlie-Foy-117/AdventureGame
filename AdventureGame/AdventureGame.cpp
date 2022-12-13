// AdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Feature.h"
#include "Area.h"
#include "Potion.h"

#include <map>

int main()
{

    //player classes
    Player cayde("Cayde", "Gunslinger", 20, 10, nullptr);


    //monster classes
    Monster swampDweller("Swamp Dweller", "Slimy ball of squeakling moss", 20, 15);

    Monster runedGolem("Runed Golem", "An ancient relic of a twisted people", 8, 25);

    Monster demonGhost("Demon Ghost", "A gaseous cloud of pure evil", 10, 5);

    //area classes

    Area wailingMarsh("Wailing_Marsh", "Wailing Marsh: The corrupted lands that speaks", {});

    Area fallenFortress("Fallen_Fortress", "Fallen Fortress: The last memory of what once was", {});

    Area cloudedCity("Clouded_City", "Clouded City: The city above all", {});

    wailingMarsh.AddExit(&fallenFortress);
    wailingMarsh.AddExit(&cloudedCity);

    fallenFortress.AddExit(&wailingMarsh);
    fallenFortress.AddExit(&cloudedCity);

    cloudedCity.AddExit(&wailingMarsh);
    cloudedCity.AddExit(&fallenFortress);

    //Items
    Potion healthPotion("SmallHealthPotion", "This potion heals you for a small amount of health", 5);

    //feature
    /*
    Feature lock;
    lock.name = "Lock";
    lock.description = "Can be unlocked with a key";

    Feature sword;
    sword.name = "Sword";
    sword.description = "Strength potion can be used on it to increase damage";

    Feature lever;
    lever.name = "Lever";
    lever.description = "When pulled boss fight starts";
    */

    
    
    cayde.SetCurrentArea(&wailingMarsh);
    std::string userStringInput;
    int userIntInput = 0;
    bool quitGame = false;
    std::cout << "You awake in the " << cayde.GetCurrentArea()->GetName() << std::endl;
    do
    { 
        std::cout << "What would you like to do: " << std::endl
            << "   look" << std::endl
            << "   attack" << std::endl
            << "   use" << std::endl
            << "   go" << std::endl
            << "   quit" << std::endl;
        
        std::cin >> userStringInput;

        if (userStringInput == "quit")
        {
            quitGame = true;
        }
        else if (userStringInput == "look")
        {
            system("cls");

            std::cout << "Look where?" << std::endl
                << "    self" << std::endl
                << "    here" << std::endl
                << "    quit" << std::endl;

            std::cin >> userStringInput;
            if (userStringInput == "self")
            {
                system("cls");

                cayde.LookAtSelf();
            }
            if (userStringInput == "here")
            {
                system("cls");

                cayde.GetCurrentArea()->Look();
            }

        }
        else if (userStringInput == "attack")
        {
            system("cls");

            std::cout << "What would you like to attack" << std::endl
                << "    monster" << std::endl;

            std::cin >> userStringInput;

            if (userStringInput == "monster")
            {
                system("cls");
                cayde.LookAtSelf();
                if (cayde.GetCurrentArea()->GetName() == wailingMarsh.GetName())
                {
                    swampDweller.LookAtMonster();
                }

                if (cayde.GetCurrentArea()->GetName() == fallenFortress.GetName())
                {
                    runedGolem.LookAtMonster();
                }

                if (cayde.GetCurrentArea()->GetName() == cloudedCity.GetName())
                {
                    demonGhost.LookAtMonster();
                }
                std::cout << "Do you still wish to attack" << std::endl
                    << "    yes" << std::endl
                    << "    no" << std::endl;
                std::cin >> userStringInput;
                if (userStringInput == "yes")
                {
                    system("cls");
                    swampDweller.DealDamage(&cayde);
                    if (!cayde.GetAlive())
                    {
                        std::cout << "You died" << std::endl;
                        quitGame = true;
                    }
                }
                else if (userStringInput == "no")
                {
                    system("cls");
                }
            }
        }
        else if (userStringInput == "use")
        {
            std::cout << "Use what" << std::endl;
        }
        else if (userStringInput == "go")
        {

            std::cout << "Go where: " << std::endl;
            for (size_t i = 0; i < cayde.GetCurrentArea()->GetExits().size(); i++)
            {
                std::cout << cayde.GetCurrentArea()->GetExits()[i]->GetName() << std::endl;
            }
                    
            std::cin >> userStringInput;

            system("cls");
            cayde.GetCurrentArea()->Go(&cayde, userStringInput);
                      
        } 
        
    } while (quitGame == false);
}
