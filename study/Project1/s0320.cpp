#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int a;
	int b;
	int c, d;
	int result;
	/*a = 100;
	b = 200;
	result = a + b;
	printf("Hello world\n");
	printf("a�� ����� �� : %d \nb�� ����� �� : %d\n",a,b);
	printf("%d + %d = %d\n",a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);
	printf("%d\n", result);*/
	/*scanf("%d", &a);
	scanf("%d", &b);
	printf("ù ��° �о���� ���� : %d\n", a);
	printf("�� ��° �о���� ���� : %d\n", b);
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	
	if (a == 0 || b == 0) {
		printf("���ϱ⸦ ����� �� �����ϴ�.\n");
		printf("�����⸦ ����� �� �����ϴ�.\n");
	}else{
		printf("%d * %d = %d\n", a, b, a * b);
		printf("%d / %d = %d\n", a, b, a / b);
	}*/
	/*if (b != 0) {
		printf("%d / %d = %d\n", a, b, a / b);
	}*/
	/*printf("ù ��° ����� ���� �Է��ϼ��� ==>");
	scanf("%d", &a);
	printf("�� ��° ����� ���� �Է��ϼ��� ==>");
	scanf("%d", &b);
	printf("�� ��° ����� ���� �Է��ϼ��� ==>");
	scanf("%d", &c);
	printf("�� ��° ����� ���� �Է��ϼ��� ==>");
	scanf("%d", &d);
	printf("%d + %d + %d + %d = %d", a, b, c, d, a + b + c + d);*/
	
	/*scanf("%d", &a);
	scanf("%d", &b);
	q
	if (a > b) 
		printf("a�� %d��ŭ Ů�ϴ�", a - b);
	else if(b == a) 
		printf("�� ���� �����ϴ�.");
	else 
		printf("b�� %d��ŭ Ů�ϴ�", b - a);*/


	printf("ù ��° ����� ���� �Է��ϼ��� ==>");
	scanf("%d", &a);
	printf("<1>���� <2>���� <3>���� <4>������ <5>������ ==>");
	scanf("%d", &b);
	printf("�� ��° ����� ���� �Է��ϼ��� ==>");
	scanf("%d", &c);
	if (b == 1) {
		printf("%d + %d = %d", a, c, a + c);
	}
	else if (b == 2) {
		printf("%d - %d = %d", a, c, a - c);
	}
	else if (b == 3) {
		if (c == 0) {
			printf("����� �� �����ϴ�.");
		}
		else {
			printf("%d * %d = %d", a, c, a * c);
		}
	}
	else if (b == 4) {
		if (c==0) {
			printf("����� �� �����ϴ�.");
		}
		else {
			printf("%d / %d = %.2f", a, c, (float)a / c);
		}
	}
	else if (b == 5) {
		print("%d % %d = %.2f",a,c,(float)a%c)
	}
	else{
		printf("���� �����Դϴ�");
	}
	                            
}