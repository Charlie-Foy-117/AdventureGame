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
        << "Armour: " << playerInfo.armour << std::endl;
       // << "Inventory: " << playerInfo.inventory << std::endl;
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
    cayde.inventory = { "bullets", cayde.weapon, cayde.armour + " armour" };

    Player ikora;
    ikora.name = "Ikora";
    ikora.description = "Mage";
    ikora.health = 50;
    ikora.attack = 40;
    ikora.weapon = "Condensed Void";
    ikora.armour = "Robes of Magnus set";
    ikora.inventory = { "energy crystals", ikora.weapon, ikora.armour + " armour" };

    Player zavala;
    zavala.name = "Zavala";
    zavala.description = "Tank";
    zavala.health = 150;
    zavala.attack = 10;
    zavala.weapon = "Fists of Flurry";
    zavala.armour = "Battleworn Metal set";
    zavala.inventory = { "rage booster", zavala.weapon, zavala.armour + " armour" };

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
    swampDweller.description = "King of the old kind, Conqueuer of the new";
    swampDweller.health = 500;
    swampDweller.attack = 40;

    //area classes
    Area wailingMarsh;
    wailingMarsh.name = "Wailing Marsh";
    wailingMarsh.decription = "The corrupted lands that speaks";
    wailingMarsh.contents = {};
    wailingMarsh.exits = { "Northern passge way", "Drowned gateway" };

    Area fallenFortress;
    fallenFortress.name = "Fallen Fortress";
    fallenFortress.decription = "The last memory of what once was";
    fallenFortress.contents = {};
    fallenFortress.exits = { "Eastern pathway", "Road to the undercove", "The pit" };

    Area cloudedCity;
    cloudedCity.name = "Clouded City";
    cloudedCity.decription = "The city above all";
    cloudedCity.contents = {};
    cloudedCity.exits = { "Stairway up", "The cloud bridge" };

    //feature
    Feature null;
    null.name = "";
    null.description = "";

    Feature null;
    null.name = "";
    null.description = "";

    Feature null;
    null.name = "";
    null.description = "";

    //item
    Item healthPot;
    healthPot.name = "Potion of restoration";
    healthPot.description = "Will heal player for 20 health points";

    Item key;
    key.name = "Potion of strength";
    key.description = "Will make next attack done by player deal an addtional 20 points";

    Item mossCrown;
    mossCrown.name = "Crown of Moss";
    mossCrown.description = "Does nothing, player looks cool";
}
