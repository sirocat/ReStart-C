#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

void main() {
	/*int i, line, star;

	printf("����ϰ���� �ټ� �Է� : ");
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
//printf("���� �Է�:");
//scanf("%d", &innum);
//i = 1;
//while (i <= innum) {
//	if (i % 5 == 0 || i % 7 == 0)
//		sum = sum + i;
//	i++;
//}
//printf("1���� 5������ �� : %d", sum);


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
		printf("\n �մ� �ֹ��Ͻðڽ��ϱ� \n");
		printf("<1> ī��� <2>īǪġ�� <3>�Ƹ޸�ī�� <4>�׸� ��ų����");
		scanf("%d", &menu);

		switch (menu) {
		case 1: printf("ī��󶼸� �ֹ��Ͽ����ϴ�\n"); break;
		case 2: printf("īǪġ�븦 �ֹ��Ͽ����ϴ�\n"); break;
		case 3: printf("�Ƹ޸�ī�븦 �ֹ��Ͽ����ϴ�\n"); break;
		case 4: printf("�ֹ��Ͻ� Ŀ�Ǹ� �ֹ��Ͽ����ϴ�\n"); break;
		default: printf("�߸� �Է��ϼ̽��ϴ�\n"); break;
		}
	} while (menu != 4);*/


	/*int i,start, end, step, sum = 0;
		printf("�հ��� ���� �� : ");
		scanf("%d", &start);
		printf("�հ��� �� �� : ");
		scanf("%d", &end);
		printf("��� : ");
		scanf("%d", &step);
		i = start;
		while (i <= end) {
			if (i % step == 0) {
				sum = sum + i;
			}
			i++;
		}
		printf("%d���� %d������ %d�� ����� �� : %d", start, end,step,sum);*/



		/*char str[100];
			int i,uppcnt=0, lowcnt=0, numcnt = 0;
			printf("���ڿ� �Է� : ");
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
			printf("�빮�� ���� %d �ҹ��� ���� %d ���ڰ��� %d\n", uppcnt, lowcnt, numcnt);*/