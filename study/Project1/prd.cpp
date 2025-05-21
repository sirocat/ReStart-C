#include <stdio.h>
#define SIZE 100

int car[SIZE][SIZE];

void initializeCar() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            car[i][j] = 0;
}

void drawCar() {
    // 본체 (더 넓고 높게)
    for (int i = 20; i < 30; i++) {
        for (int j = 5; j < 35; j++) {
            car[i][j] = 1;
        }
    }

    // 윗부분 루프 (3줄만)
    for (int i = 15; i < 20; i++) {  // 3줄로 변경
        for (int j = 12; j < 28; j++) {
            car[i][j] = 1;
        }
    }

    // 창문 (위 루프에 비워내기)
    for (int i = 16; i < 20; i++) {  // 창문 높이도 동일하게
        for (int j = 14; j < 17; j++) {
            car[i][j] = 0;
        }
        for (int j = 23; j < 26; j++) {
            car[i][j] = 0;
        }
    }

    // 바퀴 (두툼하게)
    for (int i = 30; i < 33; i++) {
        for (int j = 10; j < 14; j++) {
            car[i][j] = 1;
        }
        for (int j = 26; j < 30; j++) {
            car[i][j] = 1;
        }
    }
}

void printCar() {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            printf("%c", car[i][j] ? '0' : ' ');
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
