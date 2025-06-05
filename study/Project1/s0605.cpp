#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getNumber() {
	return rand() % 45 + 1;
}

int main() {
	short int lotto[6] = { 0, };
	int i, k, num;
	char dup = 'N';

	printf(" ** 로또 추첨을 시작합니다. ** \n\n");
	srand((unsigned)time(NULL)); 

	for (i = 0; i < 6;) {
		num = getNumber();
		for (k = 0; k < 6; k++)
			if (lotto[k] == num)
				dup = 'Y';
		if (dup == 'N')
			lotto[i++] = num;
		else
			dup = 'N';
	}
	
	printf("\n추첨된 로또 번호: ");
	for (i = 0; i < 6; i++) {
		printf("%d ", lotto[i]);
	}
	printf("\n");

	return 0;
}



