#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

void main() {
	/*int i, line, star;

	printf("출력하고싶은 줄수 입력 : ");
	scanf("%d", &line);

	i = 1;
	while (i <= line) {
		star = 1;
		while (star <= i) {
			printf("*");
			star++;
		}
		printf("\n");
		i++;
	}*/

	int i, j;
	i = 1;
	while (i <= 9) {
		j = 2;
		while(j <= 5) {
			printf("%d * %d = %d\t", j, i, j * i);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 1;
	printf("\n");
	while (i <= 9) {
		j = 6;
		while(j <= 9) {
			printf("%d * %d = %d\t", j, i, j * i);
			j++;
		}
		printf("\n");
		i++;
	}


	/*for (int j = 1; j <= 9; j++) {
		for (int i = 2; i <= 5; i++) {
			printf("%d * %d = %d\t", i, j, i * j);
		}
		printf("\n");
	}
	printf("\n");
	for (int j = 1; j <= 9; j++) {
		for (int i = 6; i <= 9; i++) {
			printf("%d * %d = %d\t", i, j, i * j);
		}
		printf("\n");
	}*/

}

//int i, sum = 0, innum;
//printf("숫자 입력:");
//scanf("%d", &innum);
//i = 1;
//while (i <= innum) {
//	if (i % 5 == 0 || i % 7 == 0)
//		sum = sum + i;
//	i++;
//}
//printf("1부터 5까지의 합 : %d", sum);


//int i, j;
//
//i = 1;
//while (i <= 5) {
//	j = 1;
//	while (j <= i) {
//		printf("*");
//		j++;
//	}
//	printf("\n");
//	i++;
//}


/*int menu;
	do {
		printf("\n 손님 주문하시겠습니까 \n");
		printf("<1> 카페라떼 <2>카푸치노 <3>아메리카노 <4>그만 시킬래요");
		scanf("%d", &menu);

		switch (menu) {
		case 1: printf("카페라떼를 주문하였습니다\n"); break;
		case 2: printf("카푸치노를 주문하였습니다\n"); break;
		case 3: printf("아메리카노를 주문하였습니다\n"); break;
		case 4: printf("주문하신 커피를 주문하였습니다\n"); break;
		default: printf("잘못 입력하셨습니다\n"); break;
		}
	} while (menu != 4);*/


	/*int i,start, end, step, sum = 0;
		printf("합계의 시작 값 : ");
		scanf("%d", &start);
		printf("합계의 끝 값 : ");
		scanf("%d", &end);
		printf("배수 : ");
		scanf("%d", &step);
		i = start;
		while (i <= end) {
			if (i % step == 0) {
				sum = sum + i;
			}
			i++;
		}
		printf("%d에서 %d까지의 %d의 배수의 합 : %d", start, end,step,sum);*/



		/*char str[100];
			int i,uppcnt=0, lowcnt=0, numcnt = 0;
			printf("문자열 입력 : ");
			scanf("%s", str);
			i = 0;
			while (i < 100) {
				if (str[i] >= 'A' && str[i] <= 'Z') {
					uppcnt++;
				}
				if (str[i] >= 'a' && str[i] <= 'z') {
					lowcnt++;
				}
				if (str[i] >= '0' && str[i] <= '9') {
					numcnt++;
				}
				i++;
			}
			printf("대문자 개수 %d 소문자 개수 %d 숫자개수 %d\n", uppcnt, lowcnt, numcnt);*/