#include "monsters.h"

// The function to move the player and update the map
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

    // Check if the player entered a valid direction and update the new position if the direction is valid
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
        if (map[newX][newY] == 'M') {
            // Player has encountered a merchant
            monsterF();
            if (monster.hp <= 0) {
                // Clear the player's previous position on the map
                clearScreen();
                map[player.posX][player.posY] = '.';

                // Update player position
                player.posX = newX;
                player.posY = newY;
            }
        } else 
        {
            // Clear the player's previous position on the map
            clearScreen();
            map[player.posX][player.posY] = '.';

            // Update player position
            player.posX = newX;
            player.posY = newY;
        }    
    } else {
        printf("You can't move in that direction.\n");
        return;
    }
    // Place player at new position
    clearScreen();
    map[player.posX][player.posY] = 'P';
}