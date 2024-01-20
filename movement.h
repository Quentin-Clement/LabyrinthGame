#include "merchant.h"

void movePlayer() {
    int newX = player.posX;
    int newY = player.posY;
    char key;
    int numChars;

    // Ask for direction and move player
    printf("Enter direction (z/q/s/d): ");
    numChars = scanf(" %c", &key);

    if (numChars != 1) {
        // More than one character entered, ignore
        printf("Invalid input. Please enter only one character.\n");
        return;
    }

    switch (key) {
        case 'z':
            newX--; // move up
            break;
        case 's':
            newX++; // move down
            break;
        case 'q':
            newY--; // move left
            break;
        case 'd':
            newY++; // move right
            break;
        default:
            printf("Invalid direction. Please enter 'z' for up, 's' for down, 'q' for left, or 'd' for right.\n");
            return;
    }

    // Check if the new position is within the map and not a wall
    if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && map[newX][newY] != '#') {
        // Clear the player's previous position on the map
        map[player.posX][player.posY] = '.';

        // Update player position
        player.posX = newX;
        player.posY = newY;
    }

    // Clear the terminal screen
    clearScreen();

    // Place player at new position
    map[player.posX][player.posY] = 'P';
}