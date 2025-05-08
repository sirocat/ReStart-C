#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

void main() {

	int i = 0;
		for (i = 1;i <= 10;i++) {
			printf("%d \n", i);
		}

	/*int i;
	for (i = 10;i >= 1;i--) {
		printf("%d \n", i);
	}*/

	/*int i;
	for (i = 2;i <= 20;i += 2) {
		printf("%d \n", i);
	}*/

	/*int i;
	for (i = 1;i <= 9;i++) {
		printf(" 7 * %d = %d\n",i,(7 * i));
	}*/

	//int i,sum=0;
	//for (i = 1;i <= 5;i++) {
	//	sum += i;
	//}
	//printf("1부터 5까지의 합 : %d", sum);


	/*for (int i = 0; i <= 8; i += 2) {

		for (int j = 0; j < (9 - i) / 2; j++) {
			printf(" ");
		}


		for (int k = 0; k <= i; k++) {
			printf("*");
		}

		printf("\n");
	}*/

}




	/*for (int i = 3;i <= 100;i += 3) {
		printf("%d\n",i);
	}*/

	//for (int i = 65;i <= 90;i++) {
	//	printf("%c ", i);
	//}
	//for (char c = 'A'; c <= 'Z'; c++) {
	//	printf("%c ", c);
	//}

	/*for (int i = 2;i <= 9;i++) {
		printf("%d단\n", i);
		for (int j = 1;j <= 9;j++) {
			printf("%d * %d = %d\n",i,j,i*j);
		}
		printf("\n");
	}*/






}


	/*int year;
	int a;
	printf("출생연도를 입력하세요 : ");
	scanf("%d", &year);
	a = year % 12;

	if (a == 0) {
		printf("원숭이 띠 입니다\n");
	}
	else if (a == 1) {
		printf("닭 띠 입니다\n");
	}
	else if (a == 2) {
		printf("개 띠 입니다\n");
	}
	else if (a == 3) {
		printf("돼지 띠 입니다\n");
	}
	else if (a == 4) {
		printf("쥐 띠 입니다\n");
	}
	else if (a == 5) {
		printf("소 띠 입니다\n");
	}
	else if (a == 6) {
		printf("호랑이 띠 입니다\n");
	}
	else if (a == 7) {
		printf("토끼 띠 입니다\n");
	}
	else if (a == 8) {
		printf("용 띠 입니다\n");
	}
	else if (a == 9) {
		printf("뱀 띠 입니다\n");
	}
	else if (a == 10) {
		printf("말 띠 입니다\n");
	}
	else if (a == 11) {
		printf("양 띠 입니다\n");
	}*/


	/*int a, b;
		char op;
		printf("수식을 한 줄로 띄어쓰기로 입력하세요 : ");
		scanf("%d %c %d", &a, &op, &b);

		switch (op)
		{
			case '+': printf("%d + %d = %d", a, b, a + b); break;
			case '-': printf("%d - %d = %d", a, b, a - b); break;
			case '*': printf("%d * %d = %d", a, b, a * b); break;
			case '/':
				if (b != 0) {
					printf("%d / %d = %d", a, b, a / b); break;
				}
				else {
					printf("계산 불가능"); break;
				}
			case '%':
				if (b != 0) {
					printf("%d %% %d = %d", a, b, a % b); break;
				}
				else {
					printf("계산 불가능"); break;
				}
			default: break;
		}*/

