#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <unistd.h>

#define MAX_ARMOR_PIECES 10
#define SIZE 15

// Labyrinth map
char map[SIZE][SIZE] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'G', '.', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', 'G', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '#'},
    {'#', 'M', '#', '.', '#', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', 'M', '.', '.', '#', '.', '#', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '#', '#', '#', '.', '.', '.', '.', '.', 'M', '#', '.', '#', '#'},
    {'#', '.', '.', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '#', '#', 'M', '.', '.', '.', '.', '.', '#', '#'},
    {'#', 'M', '.', '.', '.', 'M', '.', '.', '#', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', 'M', '.', '#'},
    {'#', 'G', '.', '.', '#', '.', 'M', '.', '#', '#', '#', '#', '#', 'G', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

typedef struct weapon {
    char *name;
    int damage;
    int price;
} weapon_t;

// TODO:
typedef struct spell {
    char *name;
    int damage;
    int price;
} spell_t;

typedef struct player {
    char name[20];
    int hp;
    int armor;
    int gold;
    int posX;  // Player's current row in the labyrinth
    int posY;  // Player's current column in the labyrinth
    weapon_t weapon;
    spell_t spell;
} player_t;

typedef struct monster {
    char name [20];
    int hp;
    int damage;
    int reward;
} monster_t;

// Initialize the player and the monster (only one monster at the moment)
player_t player = {"", 100, 0, 50, 7, 7, {"", 0, 0}, {"", 0, 0}};
monster_t monster = {"Monster", 150, 20, 100};

// Initialize weapons
weapon_t sword = {"Sword", 25, 40};
weapon_t axe = {"Axe", 50, 100};
weapon_t bow = {"Bow", 100, 300};

// void drawLabyrinth();

// Initialize player's name
void intializePlayer()
{
    printf("What will be your character's name?\n");
    scanf("%s", player.name);
}

// Initialize the map with the player's initial position
void initializeMap() {
    // Set the player's initial position
    map[player.posX][player.posY] = 'P';
}

// To display the player's inventory and stats
void inventory(){
    printf("%d hp %d armor %d damage %d gold\n\n", player.hp, player.armor, player.weapon.damage, player.gold);
}

// To display the map
void printMap() {
    initializeMap();

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n______________________________\n\n");
}

// To clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// To clear the screen and display the permanent information (inventory and map)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    inventory();
    printMap();
}