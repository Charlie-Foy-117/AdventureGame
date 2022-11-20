// AdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Feature.h"
#include "Item.h"
#include "Area.h"

#include <map>

int main()
{

    //player classes
    Player cayde("Cayde", "Gunslinger", 90, 25, nullptr);


    //monster classes
    /*
    Monster swampDweller;
    swampDweller.name = "Swamp Dweller";
    swampDweller.description = "Slimy ball of squeakling moss";
    swampDweller.health = 5;
    swampDweller.attack = 1;

    Monster rustee;
    rustee.name = "Rust-EE";
    rustee.description = "A relic of a better age";
    rustee.health = 30;
    rustee.attack = 10;

    Monster allfather;
    allfather.name = "The Allfather of the Distant Shores";
    allfather.description = "King of the old kind, Conqueuer of the new";
    allfather.health = 500;
    allfather.attack = 40;
    */


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


    //item
    /*
    Item healthPot;
    healthPot.name = "Potion of restoration";
    healthPot.description = "Will heal player for 20 health points";

    Item strenPot;
    strenPot.name = "Potion of strength";
    strenPot.description = "Will make next attack done by player deal an addtional 20 points";

    Item key;
    key.name = "Key";
    key.description = "Unlocks lock";
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
            << "   quit" << std::endl;
        
        std::cin >> userStringInput;

        if (userStringInput == "quit")
        {
            quitGame = true;
        }
        if (userStringInput == "look")
        {
            system("cls");

            std::cout << "Look where?" << std::endl
                << "    here" << std::endl
                << "    quit" << std::endl;

            std::cin >> userStringInput;

            if (userStringInput == "quit")
            {
                quitGame = true;
            }
            if (userStringInput == "here")
            {
                system("cls");

                cayde.GetCurrentArea()->Look();

                std::cout << "What would you like to do: " << std::endl
                    << "   go" << std::endl
                    << "   quit" << std::endl;

                std::cin >> userStringInput;
                if (userStringInput == "quit")
                {
                    quitGame = true;
                }
                if (userStringInput == "go")
                {
                    system("cls");

                    std::cout << "Go where: " << std::endl;
                    for (size_t i = 0; i < cayde.GetCurrentArea()->GetExits().size(); i++)
                    {
                        std::cout << cayde.GetCurrentArea()->GetExits()[i]->GetName() << std::endl;
                    }
                    
                    std::cin >> userStringInput;
                    
                    system("cls");
                    cayde.GetCurrentArea()->Go(&cayde, userStringInput);
                      
                }
            }
        }
        
    } while (quitGame == false);
}
