#include <stdio.h> 
#define SIZE 700

int car[SIZE][SIZE];

void initializeCar() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            car[i][j] = 0;
}

void drawCar() {
    // 본체
    for (int i = 220; i < 300; i++) {
        for (int j = 50; j < 500; j++) {
            car[i][j] = 1;
        }
    }

    // 윗부분
    for (int i = 150; i < 300; i++) {
        for (int j = 120; j < 430; j++) {
            car[i][j] = 1;
        }
    }

    // 창문 1, 2
    for (int i = 160; i < 200; i++) {
        for (int j = 180; j < 220; j++) {
            car[i][j] = 0;
        }
        for (int j = 330; j < 370; j++) {
            car[i][j] = 0;
        }
    }

    // 바퀴
    for (int i = 300; i < 350; i++) {
        for (int j = 130; j < 220; j++) {
            car[i][j] = 1;
        }
        for (int j = 330; j < 420; j++) {
            car[i][j] = 1;
        }
    }

    // 왼쪽 바퀴 가운데 구멍
    for (int i = 310; i < 335; i++) {
        for (int j = 160; j < 190; j++) {
            car[i][j] = 0;
        }
    }

    // 오른쪽 바퀴 가운데 구멍
    for (int i = 310; i < 335; i++) {
        for (int j = 360; j < 390; j++) {
            car[i][j] = 0;
        }
    }
}

void printCar() {
    for (int i = 0; i < 150; i++) {  //공백으로 위에 자동차 위치 내려오게하기
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
