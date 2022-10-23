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
    cayde.currentArea = "Wailing Marsh";
    cayde.inventory = { "Bullets", cayde.weapon, cayde.armour + " armour" };

    Player ikora;
    ikora.name = "Ikora";
    ikora.description = "Mage";
    ikora.health = 50;
    ikora.attack = 40;
    ikora.weapon = "Condensed Void";
    ikora.armour = "Robes of Magnus set";
    ikora.currentArea = "Wailing Marsh";
    ikora.inventory = { "Energy crystals", ikora.weapon, ikora.armour + " armour" };

    Player zavala;
    zavala.name = "Zavala";
    zavala.description = "Tank";
    zavala.health = 150;
    zavala.attack = 10;
    zavala.weapon = "Fists of Flurry";
    zavala.armour = "Battleworn Metal set";
    zavala.currentArea = "Wailing Marsh";
    zavala.inventory = { "Rage booster", zavala.weapon, zavala.armour + " armour" };
    


    //monster classes
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


    //area classes
    Area wailingMarsh;
    wailingMarsh.name = "Wailing_Marsh";
    wailingMarsh.description = "Wailing Marsh: The corrupted lands that speaks";
    wailingMarsh.contents = {"Swamp Dweller", "Health Potion", "Swords"};
    wailingMarsh.exits = { "Clouded_City", "Fallen_Fortress" };

    Area fallenFortress;
    fallenFortress.name = "Fallen_Fortress";
    fallenFortress.description = "Fallen Fortress: The last memory of what once was";
    fallenFortress.contents = {"Strength Potion", "Rust-EE", "Key"};
    fallenFortress.exits = { "Wailing_Marsh", "Clouded_City" };

    Area cloudedCity;
    cloudedCity.name = "Clouded_City";
    cloudedCity.description = "Clouded City: The city above all";
    cloudedCity.contents = {"Lever", "Allfather", "Lock"};
    cloudedCity.exits = { "Fallen_Fortress", "Wailing_Marsh" };

    Area currentArea;
    currentArea.name = "";
    currentArea.description = "";
    currentArea.contents = {};
    currentArea.exits = {};

    std::map<std::string, Area> areaMap;
    areaMap[wailingMarsh.name] = wailingMarsh;
    areaMap[fallenFortress.name] = fallenFortress;
    areaMap[cloudedCity.name] = cloudedCity;
    
    //feature
    Feature lock;
    lock.name = "Lock";
    lock.description = "Can be unlocked with a key";

    Feature sword;
    sword.name = "Sword";
    sword.description = "Strength potion can be used on it to increase damage";

    Feature lever;
    lever.name = "Lever";
    lever.description = "When pulled boss fight starts";


    //item
    Item healthPot;
    healthPot.name = "Potion of restoration";
    healthPot.description = "Will heal player for 20 health points";

    Item strenPot;
    strenPot.name = "Potion of strength";
    strenPot.description = "Will make next attack done by player deal an addtional 20 points";

    Item key;
    key.name = "Key";
    key.description = "Unlocks lock";
    
    
    //ikora.PrintPlayer();
    //ikora.Go("Fallen Fortress");
    //ikora.PrintPlayer();
    //fallenFortress.Look();
    //wailingMarsh.PrintArea(); 
    //swampDweller.PrintMonster();
    //lock.PrintFeature();
    //healthPot.PrintItem();
    
    currentArea = wailingMarsh;
    std::string userStringInput;
    int userIntInput = 0;
    bool quitGame = false;
    std::cout << "You awake in the " << currentArea.name << std::endl;
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

                currentArea.Look();

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
                    for (size_t i = 0; i < currentArea.exits.size(); i++)
                    {
                        std::cout << currentArea.exits[i] << std::endl;
                    }
                    
                    std::cin >> userStringInput;
                    
                    if (areaMap.find(userStringInput) != areaMap.end())
                    {
                        system("cls");

                        currentArea = areaMap[userStringInput]; 
                        std::cout << currentArea.name << std::endl;
                    } 
                }
            }
        }
        
    } while (quitGame == false);
}
