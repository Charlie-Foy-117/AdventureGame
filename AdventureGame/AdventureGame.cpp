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
    Player cayde;
    cayde.name = "Cayde";
    cayde.description = "Gunslinger";
    cayde.health = 90;
    cayde.attack = 25;
    cayde.weapon = "Flaming pistol";
    cayde.armour = "Cowboy set";
    cayde.inventory = { "Bullets", cayde.weapon, cayde.armour + " armour" };
    

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

    Area wailingMarsh;
    wailingMarsh.name = "Wailing_Marsh";
    wailingMarsh.description = "Wailing Marsh: The corrupted lands that speaks";
    wailingMarsh.contents = {"Swamp Dweller", "Health Potion", "Swords"};

    Area fallenFortress;
    fallenFortress.name = "Fallen_Fortress";
    fallenFortress.description = "Fallen Fortress: The last memory of what once was";
    fallenFortress.contents = {"Strength Potion", "Rust-EE", "Key"};

    Area cloudedCity;
    cloudedCity.name = "Clouded_City";
    cloudedCity.description = "Clouded City: The city above all";
    cloudedCity.contents = {"Lever", "Allfather", "Lock"};

    wailingMarsh.exits.push_back(&fallenFortress);
    wailingMarsh.exits.push_back(&cloudedCity);

    fallenFortress.exits.push_back(&wailingMarsh);
    fallenFortress.exits.push_back(&cloudedCity);

    cloudedCity.exits.push_back(&wailingMarsh);
    cloudedCity.exits.push_back(&fallenFortress);

    std::map<std::string, Area> areaMap;
    areaMap[wailingMarsh.name] = wailingMarsh;
    areaMap[fallenFortress.name] = fallenFortress;
    areaMap[cloudedCity.name] = cloudedCity;

    
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
    
    
    cayde.currentArea = &wailingMarsh;
    std::string userStringInput;
    int userIntInput = 0;
    bool quitGame = false;
    std::cout << "You awake in the " << cayde.currentArea->name << std::endl;
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

                cayde.currentArea->Look();

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
                    for (size_t i = 0; i < cayde.currentArea->exits.size(); i++)
                    {
                        std::cout << cayde.currentArea->exits[i]->name << std::endl;
                    }
                    
                    std::cin >> userStringInput;
                    
                    system("cls");
                    cayde.currentArea->Go(&cayde, userStringInput);
                      
                }
            }
        }
        
    } while (quitGame == false);
}
