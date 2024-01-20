#include "merchant.h"

// Print the encounter information
void printEncounterInfo() {
    printf("You have encountered a monster!\n");
    printf("You have %d HP, the monster has %d HP.\n", player.hp, monster.hp);
}

// Update the monster's HP after the player attacks
void attackMonster() {
    printf("You attack the monster!\n");
    monster.hp -= player.weapon.damage;
    printf("The monster has %d HP left.\n", monster.hp);
}

// Update the player's HP and armor after the monster attacks
void handleMonsterAttack() {
    printf("The monster attacks you!\n");
    int damagesThisTurn = monster.damage;

    // Reduce damages by the player's armor
    while (player.armor > 0 && damagesThisTurn > 0) {
        player.armor--;
        damagesThisTurn--;
    }

    player.hp -= damagesThisTurn;

    if (player.hp <= 0) {
        clearScreen();
        printf("You have been defeated by the monster!\n");
        printf("GAME OVER\n");
        exit(0);
    }

    printf("You have %d HP and %d armor left.\n", player.hp, player.armor);
}

// Handle the player's attempt to run away
void handleRunAttempt(int successChance) {
    printf("You attempt to run away from the monster!\n");

    // Introduce some chance of success
    if (rand() % successChance == 0) {
        printf("You successfully escape!\n");
        sleep(3);
    } else {
        int damagesThisTurn = monster.damage;
        player.hp -= damagesThisTurn;

        printf("The monster catches up with you and takes away %d HP!\n", damagesThisTurn);
        sleep(3);

        if (player.hp <= 0) {
            printf("You have been defeated by the monster!\n");
            printf("GAME OVER\n");
            exit(0);
        }

        printf("You have %d HP left.\n", player.hp);
    }
}

// What happens when the player encounters a monster
void monsterF() {
    printEncounterInfo();

    // Variable to track if the player successfully runs away
    int runSuccessful = 0;

    // Keep fighting until the monster is defeated or the player runs away
    while (monster.hp > 0 && !runSuccessful) {
        printf("What do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Run\n");
        printf("Enter your choice: ");
        int choice;

        if (scanf("%d", &choice) != 1) {
            // Invalid input, clear the buffer
            clearInputBuffer();
            clearScreen();
            printf("Invalid choice. Please enter a number.\n");
            continue;
        }

        clearScreen();

        switch (choice) {
            case 1:
                // Attack
                attackMonster();

                if (monster.hp <= 0) {
                    printf("You have defeated the monster!\n");
                    printf("You receive %d gold.\n", monster.reward);
                    player.gold += monster.reward;
                } else {
                    handleMonsterAttack();
                }
                break;

            case 2:
                // Run
                handleRunAttempt(2); // You can adjust the success chance as needed
                runSuccessful = 1;
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

