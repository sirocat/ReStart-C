#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL 35
#define TEAM_SIZE 2
#define NUM_TEAMS 17

void shuffle(int* array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // 0���� i���� ������
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    int people[TOTAL];
    for (int i = 0; i < TOTAL; i++) {
        people[i] = i + 1;
    }

    srand(time(NULL));
    shuffle(people, TOTAL);

    printf("=== �� ���� ===\n");
    for (int i = 0; i < NUM_TEAMS * TEAM_SIZE; i += TEAM_SIZE) {
        printf("%2d��: %2d, %2d\n", (i / TEAM_SIZE) + 1, people[i], people[i + 1]);
    }

    printf("���� ���: %d\n", people[NUM_TEAMS * TEAM_SIZE]);

    return 0;
}
