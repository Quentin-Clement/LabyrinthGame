#include "movement.h"

int main() {
    char key;

    intializePlayer();

    clearScreen();
    printf("Welcome to the labyrinth, %s!\n", player.name);
    printf("You have %d hp, %d armor, and %d damage.\n", player.hp, player.armor, player.weapon.damage);
    printf("\nFirst, here is the merchant. You can buy some items from him to help you in your quest.\n");
    printf("\nPress [1] to talk to the merchant:");

    while (key != '1') {
        scanf(" %c", &key);  // added a space before %c to consume any whitespace characters
    }
    clearScreen();

    merchant();

    // Free the allocated memory for the player's name
    free(player.name);

    return 0;
}