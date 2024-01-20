#include "movement.h"

int main() {
    char key;


    clearScreen();
    intializePlayer();
    clearScreen();
    printf("Welcome to the labyrinth, %s!\n", player.name);
    printf("You received 50 gold coins so you can buy some items to prepare for your quest.\n");
    printf("\nFirst, here is the merchant. You can buy some items from him.\n");
    printf("\nPress [1] to talk to the merchant:");    

    while (1) {
        // Call the movePlayer function with the entered direction
        movePlayer();
        while (key != '1') {
            scanf(" %c", &key);  // added a space before %c to consume any whitespace characters
        }
        clearScreen();

        merchant();
    }
    return 0;
}