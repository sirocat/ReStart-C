#include <stdio.h> 
#define SIZE 700

int car[SIZE][SIZE];

void initializeCar() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            car[i][j] = 0;
}

void drawCar() {
    // º»Ã¼
    for (int i = 220; i < 300; i++) {
        for (int j = 50; j < 500; j++) {
            car[i][j] = 1;
        }
    }

    // À­ºÎºÐ
    for (int i = 150; i < 300; i++) {
        for (int j = 120; j < 430; j++) {
            car[i][j] = 1;
        }
    }

    // Ã¢¹® 1, 2
    for (int i = 160; i < 200; i++) {
        for (int j = 180; j < 220; j++) {
            car[i][j] = 0;
        }
        for (int j = 330; j < 370; j++) {
            car[i][j] = 0;
        }
    }

    // ¹ÙÄû
    for (int i = 300; i < 350; i++) {
        for (int j = 130; j < 220; j++) {
            car[i][j] = 1;
        }
        for (int j = 330; j < 420; j++) {
            car[i][j] = 1;
        }
    }

    // ¿ÞÂÊ ¹ÙÄû °¡¿îµ¥ ±¸¸Û
    for (int i = 310; i < 335; i++) {
        for (int j = 160; j < 190; j++) {
            car[i][j] = 0;
        }
    }

    // ¿À¸¥ÂÊ ¹ÙÄû °¡¿îµ¥ ±¸¸Û
    for (int i = 310; i < 335; i++) {
        for (int j = 360; j < 390; j++) {
            car[i][j] = 0;
        }
    }
}

void printCar() {
    for (int i = 0; i < 150; i++) {  // 150ÁÙ ÀÌ»ó Ãâ·ÂÇØº¸±â
        printf("\n");
    }

    for (int i = 0; i < SIZE; i += 10) {
        for (int j = 0; j < SIZE; j += 10) {
            if (car[i][j])
                printf("0");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    initializeCar();
    drawCar();
    printCar();
    return 0;
}
