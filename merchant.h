#include "header.h"

// Verify if the player has enough gold to buy the item and update the player's stats
void buyItem(weapon_t *item)
{
    if (player.gold >= item->price)
    {
        player.gold -= item->price;
        player.weapon.damage = item->damage;
        printf("You bought the %s!\n", item->name);
        printf("You now have %d gold.\n", player.gold);
        printf("You now have %d damage.\n", player.weapon.damage);
    }
    else
    {
        printf("You don't have enough gold to buy the %s.\n", item->name);
    }
}

// What happens when the player wants to buy a weapon
void handleWeapons()
{
    printf("Here are the weapons:\n");
    // Display weapons...
    // (You may need to declare and define weapons like sword, axe, and bow)
    printf("[1] %s: %d damage, %d gold\n", sword.name, sword.damage, sword.price);
    printf("[2] %s: %d damage, %d gold\n", axe.name, axe.damage, axe.price);
    printf("[3] %s: %d damage, %d gold\n\n", bow.name, bow.damage, bow.price);
    printf("Press [1] to buy the sword.\nPress [2] to buy the axe.\nPress [3] to buy the bow.\nPress [4] to leave the shop.\n");

    char key;
    scanf(" %c", &key);
    clearScreen();

    switch (key)
    {
    case '1':
        buyItem(&sword);
        break;
    case '2':
        buyItem(&axe);
        break;
    case '3':
        buyItem(&bow);
        break;
    case '4':
        // User wants to leave the shop
        break;
    default:
        // Handle invalid input
        printf("Invalid input. Please enter a valid option.\n\n");
        handleWeapons();
    }
}

// Verify if the player has enough gold to buy the armor and update the player's stats
// TODO: add a clearScreen()
void buyArmor(int armorPieces)
{
    if (player.gold >= armorPieces * 10)
    {
        player.gold -= armorPieces * 10;
        player.armor += armorPieces * 10;
        if (armorPieces == 1)
        {
            printf("You bought a piece of armor!\n");
        }
        else
        {
            printf("You bought %d pieces of armor!\n", armorPieces);
        }
        printf("You now have %d gold.\n", player.gold);
        printf("You now have %d armor points.\n", player.armor);
    }
    else
    {
        printf("\nYou don't have enough gold to buy the armor.\n");
    }
}

// What happens when the player wants to buy armor
void handleArmor()
{
    printf("A piece of armor costs 10 golds and will give you 10 armor points.\nYou can have a maximum of 100 armor points.\n");
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
        buyArmor(armorPieces);
    }
    else
    {
        clearScreen();
        printf("Alright, you don't want any armor.\n");
    }
}

// Verify the player's HP and gold and restore the player's HP if conditions are met
void restoreHealth() {
    char key;
    clearScreen();
    if (player.hp == 100) {
        printf("You already have full health.\n\n");
        return;
    } else {
        printf("You currently have %d HP.\n", player.hp);
        printf("Restoring your health will cost you 50 gold.\n");
        printf("Do you want to restore your health? [Y]es or [N]o\n");
        while (key != 'Y' && key != 'N') {
            scanf(" %c", &key);

            if (key == 'Y') {
                if (player.gold >= 50) {
                    player.gold -= 50;
                    player.hp = 100;
                    printf("You now have %d HP.\n", player.hp);
                    printf("You now have %d gold.\n", player.gold);
                } else {
                    printf("You don't have enough gold to restore your health.\n");
                }
            } else if (key == 'N') {
                printf("Alright, you don't want to restore your health.\n");
            } else {
                printf("Invalid input. Please enter a valid option.\n");
            }
        }
    }
    
}

// What happens when the player talks to the merchant
void merchant()
{
    int exit = 0;

    clearScreen();
    printf("Merchant:\nWelcome to my shop, %s!\n", player.name);
    printf("I have some items that might help you in your quest.\n\n");

    // Display the merchant's items until exit is true (when the user press 4)
    do
    {
        printf("You currently have %d gold.\n\n", player.gold);
        printf("Press [1] to look at the weapons.\nPress [2] to look at the armor.\nPress [3] to restore your health.\nPress [4] to leave the shop.\n");

        char key;

        // Wait until the user enters a valid input
        do
        {
            scanf(" %c", &key);
        } while (key != '1' && key != '2' && key != '3' && key != '4');
        clearScreen();

        switch (key)
        {
        case '1':
            handleWeapons();
            break;
        case '2':
            handleArmor();
            break;
        case '3':
            restoreHealth();
            break;
        case '4':
            // Check if the user is in the main menu or not
            if (exit == 0) {
                printf("Going back to the main menu.\n");
            } else {
                printf("Alright, see you later!\n");
            }

            exit = 1;
            break;
        default:
            // Handle invalid input
            printf("\nInvalid input. Please enter a valid option.\n");
            merchant();
        }
    } while (!exit);
}
