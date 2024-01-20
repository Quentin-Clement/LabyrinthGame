#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15

// char map[SIZE][SIZE] = {
//     {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
//     {'#', '.', '.', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#'},
//     {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#'},
//     {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '#'},
//     {'#', '.', '#', '.', '#', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#'},
//     {'#', '.', '#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
//     {'#', '.', '.', '.', '.', '.', '#', '.', '#', '#', '#', '#', '.', '#', '#'},
//     {'#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '#'},
//     {'#', '.', '.', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '.', '#'},
//     {'#', '#', '#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '#', '#'},
//     {'#', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '.', '#', '#'},
//     {'#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#', '#'},
//     {'#', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
//     {'#', '.', '.', '.', '#', '.', '.', '.', '#', '#', '#', '#', '#', '.', '#'},
//     {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
// };
 // Create a 2D array for the map

// typedef struct player {
//     int posX;
//     int posY;
// } player_t;

// player_t player = {7, 7};

// void initializeMap();

// void clearScreen() {
//     // Clear the terminal screen
//     #ifdef _WIN32
//         system("cls");
//     #else
//         system("clear");
//     #endif
// }


// void initializeMap() {
//     // Set the player's initial position
//     map[player.posX][player.posY] = 'P';
// }

// void movePlayer() {
//     int newX = player.posX;
//     int newY = player.posY;
//     char key;
//     int numChars;

//     // Ask for direction and move player
//     printf("Enter direction (z/q/s/d): ");
//     numChars = scanf(" %c", &key);

//     if (numChars != 1) {
//         // More than one character entered, ignore
//         printf("Invalid input. Please enter only one character.\n");
//         return;
//     }

//     switch (key) {
//         case 'z':
//             newX--; // move up
//             break;
//         case 's':
//             newX++; // move down
//             break;
//         case 'q':
//             newY--; // move left
//             break;
//         case 'd':
//             newY++; // move right
//             break;
//         default:
//             printf("Invalid direction. Please enter 'z' for up, 's' for down, 'q' for left, or 'd' for right.\n");
//             return;
//     }

//     // Check if the new position is within the map and not a wall
//     if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && map[newX][newY] != '#') {
//         // Clear the player's previous position on the map
//         map[player.posX][player.posY] = '.';

//         // Update player position
//         player.posX = newX;
//         player.posY = newY;
//     }

//     // Clear the terminal screen
//     clearScreen();

//     // Place player at new position
//     map[player.posX][player.posY] = 'P';
// }

void printMap() {
    initializeMap();

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    clearScreen();
    while (1) {
        printMap(); // Print the map
        // Call the movePlayer function with the entered direction
        movePlayer();
    }
    return 0;
}