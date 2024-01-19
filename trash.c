#define MAX_ARMOR_PIECES 10

int labyrinth[15][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,0,0,0,1,1,1,2,1,1,1,0,0,0,1},
    {1,0,0,0,2,2,2,2,2,2,2,0,0,0,1},
    {1,0,0,0,1,1,1,2,1,1,1,0,0,0,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} 
};

enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

typedef struct weapon {
    char *name;
    int damage;
    int price;
} weapon_t;

typedef struct spell {
    char *name;
    int damage;
    int price;
} spell_t;

typedef struct player {
    char *name;
    int hp;
    int armor;
    int gold;
    weapon_t weapon;
    spell_t spell;
} player_t;

// Initializing a default player and weapons
player_t player = {"", 100, 0, 50, {"", 10, 0}, {"", 0, 0}};
weapon_t sword = {"Sword", 25, 40};
weapon_t axe = {"Axe", 50, 100};
weapon_t bow = {"Bow", 100, 300};

// Function declarations for inventory and clearScreen
void inventory(player_t *player);
void clearScreen();

// Function declarations for buyItem, handleWeapons, buyArmor, handleArmor, and merchant
void buyItem(player_t *player, weapon_t *item);
void handleWeapons(player_t *player);
void buyArmor(player_t *player, int armorPieces);
void handleArmor(player_t *player);
void merchant(player_t *player);

void inventory(player_t *player) 
{
    printf("%d hp %d armor %d damage %d gold\n\n", player->hp, player->armor, player->weapon.damage, player->gold);
}

// Clear screen then print inventory

void clearScreen() 
{
    system("clear");
    inventory(&player);
}

#include<stdlib.h>
#include <stdio.h>

#include "header.h"

void buyItem(player_t *player, weapon_t *item)
{
    if (player->gold >= item->price)
    {
        player->gold -= item->price;
        player->weapon.damage = item->damage; // Update weapon damage
        printf("You bought the %s!\n", item->name);
        printf("You now have %d gold.\n", player->gold);
        printf("You now have %d damage.\n", player->weapon.damage);
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

#include<stdlib.h>
#include<stdio.h>

#include "merchant.h"

int main() {
    player_t player;

    // Allocate memory for the player's name
    player.name = (char *)malloc(50 * sizeof(char));  // assuming a maximum length of 49 characters

    player.gold = 50;
    player.hp = 100;
    player.armor = 0;
    player.weapon.damage = 10;
    char key;

    clearScreen();
    printf("What will be your character's name?\n");

    // Use %49s to prevent buffer overflow
    scanf("%49s", player.name);
    clearScreen();

    printf("Welcome to the labyrinth, %s!\n", player.name);
    printf("You have %d hp, %d armor, and %d damage.\n", player.hp, player.armor, player.weapon.damage);
    printf("\nFirst, here is the merchant. You can buy some items from him to help you in your quest.\n");
    printf("\nPress [1] to talk to the merchant:");

    while (key != '1') {
        scanf(" %c", &key);  // added a space before %c to consume any whitespace characters
    }
    clearScreen();

    merchant(&player);

    // Free the allocated memory for the player's name
    free(player.name);

    return 0;
}
