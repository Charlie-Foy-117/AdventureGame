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
    Player cayde("Cayde", "Gunslinger", 20, 10, nullptr, {});


    //monster classes
    Monster swampDweller("Swamp Dweller", "Slimy ball of squeakling moss", 20, 15);

    Monster runedGolem("Runed Golem", "An ancient relic of a twisted people", 8, 25);

    Monster demonGhost("Demon Ghost", "A gaseous cloud of pure evil", 10, 5);

    //area classes

    Area wailingMarsh("Wailing_Marsh", "Wailing Marsh: The corrupted lands that speaks", {}, {}, nullptr);

    Area fallenFortress("Fallen_Fortress", "Fallen Fortress: The last memory of what once was", {}, {}, nullptr);

    Area cloudedCity("Clouded_City", "Clouded City: The city above all", {}, {}, nullptr);

    //Items

    Potion smallHealthPotion("Small_Health_Potion", "This potion heals you for a small amount of health", 5);

    //Functions
    //area functions
    wailingMarsh.AddExit(&fallenFortress);
    wailingMarsh.AddExit(&cloudedCity);

    fallenFortress.AddExit(&wailingMarsh);
    fallenFortress.AddExit(&cloudedCity);

    cloudedCity.AddExit(&wailingMarsh);
    cloudedCity.AddExit(&fallenFortress);

    wailingMarsh.SetMonster(&swampDweller);

    fallenFortress.SetMonster(&runedGolem);

    cloudedCity.SetMonster(&demonGhost);

    wailingMarsh.AddItemContent(&smallHealthPotion);

    //player functions
    //cayde.AddToInventory(&healthPotion);

    

    
    cayde.SetCurrentArea(&wailingMarsh);
    std::string userStringInput;
    int userIntInput = 0;
    bool quitGame = false;
    std::cout << "You awake in the " << cayde.GetCurrentArea()->GetName() << std::endl;
    do
    { 
        std::cout << "What would you like to do: " << std::endl
            << "look" << std::endl
            << "attack" << std::endl
            << "use" << std::endl
            << "go" << std::endl
            << "quit" << std::endl;
        
        std::cin >> userStringInput;

        if (userStringInput == "quit")
        {
            quitGame = true;
        }
        else if (userStringInput == "look")
        {
            system("cls");

            std::cout << "Look where?" << std::endl
                << "self" << std::endl
                << "here" << std::endl
                << "quit" << std::endl;

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
                if (cayde.GetCurrentArea()->GetItemContents().size() >= 1)
                {
                    std::cout << "Would you like to pick up an item" << std::endl
                        << "yes" << std::endl
                        << "no" << std::endl;
                    std::cin >> userStringInput;
                    if (userStringInput == "yes")
                    {
                        system("cls");
                        std::cout << "What item would you like to pick up" << std::endl;
                        cayde.GetCurrentArea()->LookAtContents();
                        std::cin >> userStringInput;
                        if (userStringInput == smallHealthPotion.GetName())
                        {
                            cayde.GetCurrentArea()->PickUpItem(&smallHealthPotion, &cayde);
                        }
                    }
                }
            }

        }
        else if (userStringInput == "attack")
        {
            system("cls");

            std::cout << "What would you like to attack" << std::endl
                << "monster" << std::endl;

            std::cin >> userStringInput;

            if (userStringInput == "monster")
            {
                system("cls");
                cayde.LookAtSelf();
                cayde.GetCurrentArea()->GetMonster()->LookAtMonster();
                std::cout << "Do you still wish to attack" << std::endl
                    << "yes" << std::endl
                    << "no" << std::endl;
                std::cin >> userStringInput;
                if (userStringInput == "yes")
                {
                    system("cls");
                    cayde.DealDamage(cayde.GetAttack(),cayde.GetCurrentArea()->GetMonster());
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
            system("cls");
            std::cout << "Use what" << std::endl;
            cayde.LookAtInventory();
            std::cout << "back" << std::endl;
            std::cin >> userStringInput;
            if (userStringInput == smallHealthPotion.GetName())
            {
                system("cls");
                std::cout << "Use " << userStringInput << " on what" << std::endl
                    << "self" << std::endl;
                std::cin >> userStringInput;
                cayde.Use(userStringInput, &smallHealthPotion, &cayde);
            }

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
