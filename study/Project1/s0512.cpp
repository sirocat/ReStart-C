#include <stdio.h>
#include <math.h>

#define SIZE 700

int car[SIZE][SIZE];

void initializeCar() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            car[i][j] = 0;
}

void drawCircle() {
    int centerX = SIZE / 2;
    int centerY = SIZE / 2;
    int radius = 250;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int dx = j - centerX;
            int dy = i - centerY;
            if (dx * dx + dy * dy <= radius * radius) {
                car[i][j] = 1;
            }
        }
    }
}

void drawStarShape() {
    int midX = SIZE / 2;
    int midY = SIZE / 2;

    // 수직 기둥
    for (int i = midY - 180; i < midY + 180; i++) {
        for (int j = midX - 10; j < midX + 10; j++) {
            car[i][j] = 0;
        }
    }

    // 수평 윗줄
    for (int i = midY - 180; i < midY - 160; i++) {
        for (int j = midX - 150; j < midX + 150; j++) {
            car[i][j] = 0;
        }
    }

    // 좌우 대각선
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            // 왼쪽 날개
            car[midY - i][midX - 50 - i + j] = 0;
            // 오른쪽 날개
            car[midY - i][midX + 50 + i - j] = 0;
        }
    }
}

void drawTextPlaceholder() {
    // BS PROJECT 텍스트 위치를 흰 블록으로 비우기
    for (int i = 500; i < 520; i++) {
        for (int j = 270; j < 430; j++) {
            car[i][j] = 0;
        }
    }
}

void printCar() {
    for (int i = 0; i < 100; i++) printf("\n");  // 위쪽 여백

    for (int i = 200; i < 600; i += 10) {
        for (int j = 200; j < 600; j += 5) {
            if (car[i][j])
                printf("0");
            else
                printf(" ");
        }
        printf("\n");
    }

    printf("\n\n                            BS PROJECT\n");
}

int main() {
    initializeCar();
    drawCircle();
    drawStarShape();
    drawTextPlaceholder();
    printCar();
    return 0;
}
