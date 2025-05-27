#include <stdio.h>

// 캔버스 크기 정의
#define CANVAS_HEIGHT 700 // 전체 캔버스 높이
#define CANVAS_WIDTH 700  // 전체 캔버스 너비

// 그림을 그릴 2차원 배열
int canvas[CANVAS_HEIGHT][CANVAS_WIDTH];

// 그림 전체의 기준이 될 위치 (캔버스 중앙 근처)
// 전역 변수로 선언하여 모든 함수에서 접근 가능하게 함
int base_row = 150; // 시작 행 (y 좌표)
int base_col = 300; // 시작 열 (x 좌표)


void initializeCanvas() {
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            canvas[i][j] = 0; // 캔버스를 모두 빈 공간 (값 0)으로 초기화
        }
    }
}

// for 문을 활용하여 그림의 각 부분을 그리는 함수
void drawFigureWithLoops() {
    // base_row와 base_col은 이미 위에서 전역 변수로 선언되었습니다.
    // 함수 내에서 별도 선언 없이 바로 사용합니다.

    // --- 그림의 각 부분을 사각형 영역으로 나누어 그립니다 ---
    // 이 부분은 주신 아스키 아트를 보고 대략적인 크기와 위치를 정한 것입니다.

    // 1. 머리 부분 (대략적인 사각형)
    for (int i = base_row; i < base_row + 40; i++) {
        for (int j = base_col - 45; j < base_col + 45; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1; // 픽셀 채우기 (값 1)
            }
        }
    }
    // 머리 부분 - 눈 또는 안쪽 비움 (안쪽을 비움 - 값 0)
    for (int i = base_row + 10; i < base_row + 25; i++) {
        for (int j = base_col - 30; j < base_col - 15; j++) { // 왼쪽 눈/구멍
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 0;
            }
        }
        for (int j = base_col + 15; j < base_col + 30; j++) { // 오른쪽 눈/구멍
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 0;
            }
        }
    }

    // 2. 목 부분 (대략적인 사각형)
    for (int i = base_row + 40; i < base_row + 48; i++) {
        for (int j = base_col - 15; j < base_col + 15; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }

    // 3. 몸통 부분 (윗부분)
    for (int i = base_row + 48; i < base_row + 90; i++) {
        for (int j = base_col - 40; j < base_col + 40; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }

    // 4. 몸통 부분 (중앙 부분)
    for (int i = base_row + 90; i < base_row + 130; i++) {
        for (int j = base_col - 35; j < base_col + 35; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }
    // 몸통 중앙 부분 - 안쪽 비움
    for (int i = base_row + 95; i < base_row + 125; i++) {
        for (int j = base_col - 30; j < base_col + 30; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 0;
            }
        }
    }


    // 5. 몸통 부분 (아랫부분/골반)
    for (int i = base_row + 130; i < base_row + 140; i++) {
        for (int j = base_col - 20; j < base_col + 20; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }


    // 6. 다리 부분 (왼쪽)
    for (int i = base_row + 140; i < base_row + 200; i++) {
        for (int j = base_col - 30; j < base_col - 20; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }
    // 7. 다리 부분 (오른쪽)
    for (int i = base_row + 140; i < base_row + 200; i++) {
        for (int j = base_col + 20; j < base_col + 30; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }

    // 8. 발 부분 (왼쪽)
    for (int i = base_row + 200; i < base_row + 215; i++) {
        for (int j = base_col - 35; j < base_col - 15; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }
    // 9. 발 부분 (오른쪽)
    for (int i = base_row + 200; i < base_row + 215; i++) {
        for (int j = base_col + 15; j < base_col + 35; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }

    // 팔이나 더 복잡한 디테일은 사각형만으로는 표현하기 어렵습니다.
    // 필요하다면 더 세밀한 사각형으로 나누거나, 선 그리기 함수 등을 활용해야 합니다.
}

void printCanvas() {
    // 그림이 그려진 영역 주변만 출력하여 터미널에 표시합니다.
    // BASE_ROW와 BASE_COL 근처 영역을 출력하도록 설정합니다.
    // 전역 변수로 선언된 base_row와 base_col을 바로 사용합니다.
    int start_print_row = base_row - 50;
    int end_print_row = base_row + 250;
    int start_print_col = base_col - 80;
    int end_print_col = base_col + 80;

    // 출력 시작 전에 여백을 줍니다.
    for (int k = 0; k < 5; k++) {
        printf("\n");
    }

    // 지정된 영역의 캔버스 내용을 픽셀 단위로 출력합니다.
    for (int i = start_print_row; i < end_print_row; i++) {
        for (int j = start_print_col; j < end_print_col; j++) {
            // 캔버스 배열 범위 내에 있는지 확인
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                if (canvas[i][j]) {
                    printf("0"); // 값이 1이면 "0" 출력 (채워진 픽셀)
                }
                else {
                    printf(" "); // 값이 0이면 공백 출력 (빈 픽셀)
                }
            }
            else {
                printf(" "); // 캔버스 범위를 벗어나면 공백 출력
            }
        }
        printf("\n"); // 한 줄 끝날 때마다 개행
    }
}

int main() {
    initializeCanvas();      // 캔버스 초기화
    drawFigureWithLoops();   // for 문을 활용하여 그림 그리기
    printCanvas();           // 캔버스 내용 출력

    return 0;
}
