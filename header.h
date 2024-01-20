#include<stdlib.h>
#include<stdio.h>

#define MAX_ARMOR_PIECES 10
#define SIZE 15

char map[SIZE][SIZE] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '#', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '#'},
    {'#', '.', '.', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '#', '#', '.', '.', '.', '.', '.', '.', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
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
    char name[20];
    int hp;
    int armor;
    int gold;
    int posX;  // Player's current row in the labyrinth
    int posY;  // Player's current column in the labyrinth
    weapon_t weapon;
    spell_t spell;
} player_t;

typedef struct ennemy {
    char name [20];
    int hp;
    int damage;
} ennemy_t;

player_t player = {"", 100, 0, 50, 7, 7, {"", 0, 0}, {"", 0, 0}};

weapon_t sword = {"Sword", 25, 40};
weapon_t axe = {"Axe", 50, 100};
weapon_t bow = {"Bow", 100, 300};

// void drawLabyrinth();

void intializePlayer()
{
    printf("What will be your character's name?\n");
    scanf("%s", player.name);
}

void initializeMap() {
    // Set the player's initial position
    map[player.posX][player.posY] = 'P';
}

void inventory(){
    printf("%d hp %d armor %d damage %d gold\n\n", player.hp, player.armor, player.weapon.damage, player.gold);
}

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

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    inventory();
    printMap();
}