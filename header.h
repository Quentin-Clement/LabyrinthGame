#include<stdlib.h>
#include<stdio.h>

#define MAX_ARMOR_PIECES 10

int labyrinth[15][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,0,0,0,1,1,1,2,1,1,1,0,0,0,1},
    {1,0,0,0,2,2,2,2,2,2,2,0,0,0,1},
    {1,0,0,0,1,1,1,2,1,1,1,0,0,0,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} 
};

enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
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
    int damage;
    int gold;
    weapon_t weapon;
    spell_t spell;
} player_t;

player_t player = {"", 100, 0, 10, 100, {"", 0, 0}, {"", 0, 0}};

weapon_t sword = {"Sword", 25, 40};
weapon_t axe = {"Axe", 50, 100};
weapon_t bow = {"Bow", 100, 300};

void intializePlayer()
{
    printf("What will be your character's name?\n");
    scanf("%s", player.name);
}

void inventory(){
    printf("%d hp %d armor %d damage %d gold\n\n", player.hp, player.armor, player.damage, player.gold);
}

void clearScreen() {
    system("clear");
    inventory();
}