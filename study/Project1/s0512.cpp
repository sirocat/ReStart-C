#include <stdio.h>

// ĵ���� ũ�� ����
#define CANVAS_HEIGHT 700 // ��ü ĵ���� ����
#define CANVAS_WIDTH 700  // ��ü ĵ���� �ʺ�

// �׸��� �׸� 2���� �迭
int canvas[CANVAS_HEIGHT][CANVAS_WIDTH];

// �׸� ��ü�� ������ �� ��ġ (ĵ���� �߾� ��ó)
// ���� ������ �����Ͽ� ��� �Լ����� ���� �����ϰ� ��
int base_row = 150; // ���� �� (y ��ǥ)
int base_col = 300; // ���� �� (x ��ǥ)


void initializeCanvas() {
    for (int i = 0; i < CANVAS_HEIGHT; i++) {
        for (int j = 0; j < CANVAS_WIDTH; j++) {
            canvas[i][j] = 0; // ĵ������ ��� �� ���� (�� 0)���� �ʱ�ȭ
        }
    }
}

// for ���� Ȱ���Ͽ� �׸��� �� �κ��� �׸��� �Լ�
void drawFigureWithLoops() {
    // base_row�� base_col�� �̹� ������ ���� ������ ����Ǿ����ϴ�.
    // �Լ� ������ ���� ���� ���� �ٷ� ����մϴ�.

    // --- �׸��� �� �κ��� �簢�� �������� ������ �׸��ϴ� ---
    // �� �κ��� �ֽ� �ƽ�Ű ��Ʈ�� ���� �뷫���� ũ��� ��ġ�� ���� ���Դϴ�.

    // 1. �Ӹ� �κ� (�뷫���� �簢��)
    for (int i = base_row; i < base_row + 40; i++) {
        for (int j = base_col - 45; j < base_col + 45; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1; // �ȼ� ä��� (�� 1)
            }
        }
    }
    // �Ӹ� �κ� - �� �Ǵ� ���� ��� (������ ��� - �� 0)
    for (int i = base_row + 10; i < base_row + 25; i++) {
        for (int j = base_col - 30; j < base_col - 15; j++) { // ���� ��/����
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 0;
            }
        }
        for (int j = base_col + 15; j < base_col + 30; j++) { // ������ ��/����
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 0;
            }
        }
    }

    // 2. �� �κ� (�뷫���� �簢��)
    for (int i = base_row + 40; i < base_row + 48; i++) {
        for (int j = base_col - 15; j < base_col + 15; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }

    // 3. ���� �κ� (���κ�)
    for (int i = base_row + 48; i < base_row + 90; i++) {
        for (int j = base_col - 40; j < base_col + 40; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }

    // 4. ���� �κ� (�߾� �κ�)
    for (int i = base_row + 90; i < base_row + 130; i++) {
        for (int j = base_col - 35; j < base_col + 35; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }
    // ���� �߾� �κ� - ���� ���
    for (int i = base_row + 95; i < base_row + 125; i++) {
        for (int j = base_col - 30; j < base_col + 30; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 0;
            }
        }
    }


    // 5. ���� �κ� (�Ʒ��κ�/���)
    for (int i = base_row + 130; i < base_row + 140; i++) {
        for (int j = base_col - 20; j < base_col + 20; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }


    // 6. �ٸ� �κ� (����)
    for (int i = base_row + 140; i < base_row + 200; i++) {
        for (int j = base_col - 30; j < base_col - 20; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }
    // 7. �ٸ� �κ� (������)
    for (int i = base_row + 140; i < base_row + 200; i++) {
        for (int j = base_col + 20; j < base_col + 30; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }

    // 8. �� �κ� (����)
    for (int i = base_row + 200; i < base_row + 215; i++) {
        for (int j = base_col - 35; j < base_col - 15; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }
    // 9. �� �κ� (������)
    for (int i = base_row + 200; i < base_row + 215; i++) {
        for (int j = base_col + 15; j < base_col + 35; j++) {
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                canvas[i][j] = 1;
            }
        }
    }

    // ���̳� �� ������ �������� �簢�������δ� ǥ���ϱ� ��ƽ��ϴ�.
    // �ʿ��ϴٸ� �� ������ �簢������ �����ų�, �� �׸��� �Լ� ���� Ȱ���ؾ� �մϴ�.
}

void printCanvas() {
    // �׸��� �׷��� ���� �ֺ��� ����Ͽ� �͹̳ο� ǥ���մϴ�.
    // BASE_ROW�� BASE_COL ��ó ������ ����ϵ��� �����մϴ�.
    // ���� ������ ����� base_row�� base_col�� �ٷ� ����մϴ�.
    int start_print_row = base_row - 50;
    int end_print_row = base_row + 250;
    int start_print_col = base_col - 80;
    int end_print_col = base_col + 80;

    // ��� ���� ���� ������ �ݴϴ�.
    for (int k = 0; k < 5; k++) {
        printf("\n");
    }

    // ������ ������ ĵ���� ������ �ȼ� ������ ����մϴ�.
    for (int i = start_print_row; i < end_print_row; i++) {
        for (int j = start_print_col; j < end_print_col; j++) {
            // ĵ���� �迭 ���� ���� �ִ��� Ȯ��
            if (i >= 0 && i < CANVAS_HEIGHT && j >= 0 && j < CANVAS_WIDTH) {
                if (canvas[i][j]) {
                    printf("0"); // ���� 1�̸� "0" ��� (ä���� �ȼ�)
                }
                else {
                    printf(" "); // ���� 0�̸� ���� ��� (�� �ȼ�)
                }
            }
            else {
                printf(" "); // ĵ���� ������ ����� ���� ���
            }
        }
        printf("\n"); // �� �� ���� ������ ����
    }
}

int main() {
    initializeCanvas();      // ĵ���� �ʱ�ȭ
    drawFigureWithLoops();   // for ���� Ȱ���Ͽ� �׸� �׸���
    printCanvas();           // ĵ���� ���� ���

    return 0;
}
