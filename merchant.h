#include<stdlib.h>
#include <stdio.h>

#include "header.h"

void buyItem(player_t *player, weapon_t *item)
{
    if (player->gold >= item->price)
    {
        player->gold -= item->price;
        player->damage = item->damage;
        printf("You bought the %s!\n", item->name);
        printf("You now have %d gold.\n", player->gold);
        printf("You now have %d damage.\n", player->damage);
    }
    else
    {
        printf("\nYou don't have enough gold to buy the %s.\n", item->name);
    }
}

void handleWeapons(player_t *player)
{
    printf("Here are the weapons:\n");
    // Display weapons...
    // (You may need to declare and define weapons like sword, axe, and bow)
    printf("[1] %s: %d damage, %d gold\n", sword.name, sword.damage, sword.price);
    printf("[2] %s: %d damage, %d gold\n", axe.name, axe.damage, axe.price);
    printf("[3] %s: %d damage, %d gold\n", bow.name, bow.damage, bow.price);
    printf("\nPress [1] to buy the sword.\nPress [2] to buy the axe.\nPress [3] to buy the bow.\nPress [4] to leave the shop.\n");

    char key;
    do
    {
        scanf(" %c", &key);
    } while (key != '1' && key != '2' && key != '3' && key != '4');

    switch (key)
    {
    case '1':
        clearScreen();
        buyItem(player, &sword);
        break;
    case '2':
        clearScreen();
        buyItem(player, &axe);
        break;
    case '3':
        clearScreen();
        buyItem(player, &bow);
        break;
    case '4':
        // User wants to leave the shop
        break;
    default:
        // Handle invalid input
        printf("\nInvalid input. Please enter a valid option.\n");
    }
}

void buyArmor(player_t *player, int armorPieces)
{
    if (player->gold >= armorPieces * 10)
    {
        player->gold -= armorPieces * 10;
        player->armor += armorPieces * 10;
        printf("You bought %d pieces of armor!\n", armorPieces);
        printf("You now have %d gold.\n", player->gold);
        printf("You now have %d armor points.\n", player->armor);
    }
    else
    {
        printf("\nYou don't have enough gold to buy the armor.\n");
    }
}

void handleArmor(player_t *player)
{
    printf("A piece of armor costs 10 golds and will give you 10 armor points. You can have a maximum of 100 armor points\n");
    printf("\nHow many pieces of armor do you want to buy?\n");

    int armorPieces;
    do
    {
        scanf("%d", &armorPieces);

        if (armorPieces < 0 || armorPieces > MAX_ARMOR_PIECES)
        {
            printf("\nInvalid input. Please enter a valid option.\n");
        }

    } while (armorPieces < 0 || armorPieces > MAX_ARMOR_PIECES);

    if (armorPieces > 0)
    {
        clearScreen();
        buyArmor(player, armorPieces);
    }
    else
    {
        printf("\nAlright, you don't want any armor.\n");
    }
}

void merchant(player_t *player)
{
    int exit = 0;

    printf("Welcome to my shop, %s!\n", player->name);
    printf("I have some items that might help you in your quest.\n");

    do
    {
        
        printf("You currently have %d gold.\n", player->gold);
        printf("\nPress [1] to look at the weapons.\nPress [2] to look at the armor.\nPress [3] to look at the spells.\nPress [4] to leave the shop.\n");

        char key;
        do
        {
            scanf(" %c", &key);
        } while (key != '1' && key != '2' && key != '3' && key != '4');

        switch (key)
        {
        case '1':
            clearScreen();
            handleWeapons(player);
            break;
        case '2':
            clearScreen();
            handleArmor(player);
            break;
        // case '3':
        //     handleSpells(player);
        //     break;
        case '4':
            clearScreen();
            printf("Alright, see you later!\n");
            exit = 1;
            break;
        default:
            // Handle invalid input
            printf("\nInvalid input. Please enter a valid option.\n");
        }
    } while (!exit);

    // Clear the screen after
    clearScreen();
}