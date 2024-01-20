#include "movements.h"

int main() {
    char key;

    // Introduction

    clearScreen();
    intializePlayer();
    clearScreen();
    printf("Welcome to the labyrinth, %s!\n", player.name);
    printf("You have been sent here to defeat all the monsters of this labyrinth.\n");
    sleep(5);
    clearScreen();
    printf("To help you on your quest, we've listed the locations of all the monsters on your map with the letter M.\n");
    printf("We discovered that gold coins are scattered around the labyrinth, we represented them with the letter G.\n");
    sleep(10);
    clearScreen();
    printf("You received 50 gold coins so you can buy some items from the merchant to prepare your quest.\n\n");

    while (1) {
        // Check if the player is on the merchant tile
        if (map[player.posX][player.posY] == map[7][7]) {
            printf("Press [1] to talk to the merchant. Press any other key to move:");
            scanf(" %c", &key);

            if (key == '1') {   
                // Player wants to talk to the merchant
                merchant();
            } else {    
                // Player wants to move
                movePlayer();
            }
        } else {
            // Player is not on the merchant tile, just move
            movePlayer();
        }
    }

    return 0;
}
