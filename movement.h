#include "merchant.h"

void drawLabyrinth() {
    // Clear the console
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", labyrinth[i][j]);
        }
        printf("\n\n");
    }
}