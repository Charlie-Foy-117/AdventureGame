// AdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Feature.h"
#include "Item.h"
#include "Area.h"

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
    wailingMarsh.name = "Wailing Marsh";
    wailingMarsh.description = "Wailing Marsh: The corrupted lands that speaks";
    wailingMarsh.contents = {"Swamp Dweller", "Health Potion", "Swords"};
    wailingMarsh.exits = { "Northern passge way - To Clouded City", "Drowned gateway - To Fallen Fortress" };

    Area fallenFortress;
    fallenFortress.name = "Fallen Fortress";
    fallenFortress.description = "Fallen Fortress: The last memory of what once was";
    fallenFortress.contents = {"Strength Potion", "Rust-EE", "Key"};
    fallenFortress.exits = { "Eastern pathway - To Wailing Marsh", "The pit - To Clouded City" };

    Area cloudedCity;
    cloudedCity.name = "Clouded City";
    cloudedCity.description = "Clouded City: The city above all";
    cloudedCity.contents = {"Lever", "Allfather", "Lock"};
    cloudedCity.exits = { "Stairway up - To Fallen Fortress", "The cloud bridge - To Wailing Marsh" };

    
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
    
    std::string userStringInput;
    int userIntInput = 0;
    
    std::cout << "You awake in the wailing marsh" << std::endl
        << "What would you like to do: " << std::endl
        << "   look" << std::endl
        << "   help" << std::endl;

    
    std::cin >> userStringInput;
    if (userStringInput == "look")
    {
        std::cout << "Look where?" << std::endl
            << "    here" << std::endl
            << "    monster" << std::endl;
    }
    std::cin >> userStringInput;
    
  
    if (userStringInput == "here")
    {
        wailingMarsh.Look();
    }
    if (userStringInput == "monster")
    {
        swampDweller.PrintMonster();
    }
    std::cout << "What would you like to do: " << std::endl
        << "   go" << std::endl
        << "   look" << std::endl
        << "   help" << std::endl;
    std::cin >> userStringInput;

    if (userStringInput == "go")
    {
        std::cout << "Go where: " << std::endl;
        for (size_t i = 0; i < wailingMarsh.exits.size(); i++)
        {
            std::cout << i << ": " << wailingMarsh.exits[i] << std::endl;
        }
        std::cin >> userIntInput;
        cayde.Go(wailingMarsh.exits[userIntInput]);

    }
}
