// AdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Feature.h"
#include "Item.h"
#include "Area.h"
void PrintPlayer(Player playerInfo)
{
    std::cout << "Name: " << playerInfo.name << std::endl
        << "Description: " << playerInfo.description << std::endl
        << "Health: " << playerInfo.health << std::endl
        << "Attack: " << playerInfo.attack << std::endl
        << "Weapon: " << playerInfo.weapon << std::endl
        << "Armour: " << playerInfo.armour << std::endl
        << " " << std::endl;
        std::cout << playerInfo.name << "'s Inventory:" << std::endl;
        for (size_t i = 0; i < playerInfo.inventory.size(); i++)
        {
            std::cout << playerInfo.inventory[i] << std::endl;
        }
        std::cout << " " << std::endl;
}

void PrintMonster(Monster monsterInfo)
{
    std::cout << "Name: " << monsterInfo.name << std::endl
        << "Description: " << monsterInfo.description << std::endl
        << "Health: " << monsterInfo.health << std::endl
        << "Attack: " << monsterInfo.attack << std::endl
        << " " << std::endl;
}

void PrintArea(Area areaInfo)
{
    std::cout << "Name: " << areaInfo.name << std::endl
        << "Description: " << areaInfo.description << std::endl
        << "Contents: " << std::endl;
        for (size_t i = 0; i < areaInfo.contents.size(); i++)
        {
            std::cout << areaInfo.contents[i] << std::endl;
        }
        std::cout << "Exits: " << std::endl;
        for (size_t i = 0; i < areaInfo.exits.size(); i++)
        {
            std::cout << areaInfo.exits[i] << std::endl;
        }
        std::cout << " " << std::endl;
}

void PrintFeature(Feature featureInfo)
{
    std::cout << "Name: " << featureInfo.name << std::endl
        << "Description: " << featureInfo.description << std::endl
        << " " << std::endl;
}

void PrintItem(Item itemInfo)
{
    std::cout << "Name: " << itemInfo.name << std::endl
        << "Description: " << itemInfo.description << std::endl
        << " " << std::endl;
}

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

    Player ikora;
    ikora.name = "Ikora";
    ikora.description = "Mage";
    ikora.health = 50;
    ikora.attack = 40;
    ikora.weapon = "Condensed Void";
    ikora.armour = "Robes of Magnus set";
    ikora.inventory = { "Energy crystals", ikora.weapon, ikora.armour + " armour" };

    Player zavala;
    zavala.name = "Zavala";
    zavala.description = "Tank";
    zavala.health = 150;
    zavala.attack = 10;
    zavala.weapon = "Fists of Flurry";
    zavala.armour = "Battleworn Metal set";
    zavala.inventory = { "Rage booster", zavala.weapon, zavala.armour + " armour" };

    PrintPlayer(cayde);
    PrintPlayer(ikora);
    PrintPlayer(zavala);

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

    //PrintMonster(swampDweller);
    //PrintMonster(rustee);
    //PrintMonster(allfather);

    //area classes
    Area wailingMarsh;
    wailingMarsh.name = "Wailing Marsh";
    wailingMarsh.description = "The corrupted lands that speaks";
    wailingMarsh.contents = {"Swamp Dweller", "Health Potion", "Swords"};
    wailingMarsh.exits = { "Northern passge way", "Drowned gateway" };

    Area fallenFortress;
    fallenFortress.name = "Fallen Fortress";
    fallenFortress.description = "The last memory of what once was";
    fallenFortress.contents = {"Strength Potion", "Rust-EE", "Key"};
    fallenFortress.exits = { "Eastern pathway", "Road to the undercove", "The pit" };

    Area cloudedCity;
    cloudedCity.name = "Clouded City";
    cloudedCity.description = "The city above all";
    cloudedCity.contents = {"Lever", "Allfather", "Lock"};
    cloudedCity.exits = { "Stairway up", "The cloud bridge" };

    //PrintArea(wailingMarsh);
    //PrintArea(fallenFortress);
    //PrintArea(cloudedCity);

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

    //PrintFeature(feature);
    //PrintFeature(feature2);
    //PrintFeature(feature3);

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

    //PrintItem(healthPot);
    //PrintItem(strePot);
    //PrintItem(mossCrown);
}
