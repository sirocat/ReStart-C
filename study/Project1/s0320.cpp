#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {

	int a, b, c, choice;
	float area;

	printf("<1> �ﰢ�� <2>�簢�� <3>�� <4>��ٸ��� ");
	scanf("%d", &choice);
	if (choice == 1) {
		printf("�غ��� ���� �Է�: ");
		scanf("%d", &a);
		printf("���� �Է�: ");
		scanf("%d", &b);
		area = a * b * 0.5;
		printf("�غ��� %d�̰� ���̰� %d�� �ﰢ���� ���̴� : %3.f\n", a, b, area);
	}
	if (choice == 2) {
		printf("���� ���� �Է�: ");
		scanf("%d", &a);
		printf("���� ���� �Է�: ");
		scanf("%d", &b);
		area = a * b;
		printf("���� ���� %d ���� ���� %d�� �簢���� ���̴� : %.3f\n",a,b, area);
	}
	if (choice == 3) {
		printf("�������� ���� �Է�: ");
		scanf("%d", &a);
		area = a * a * 3.14;
		printf("�������� ���̰� %d�� ���� ���̴� : %.3f\n", a, area);
	}
	if (choice == 4) {
		printf("������ ���� �Է�: ");
		scanf("%d", &a);
		printf("�Ʒ����� ���� �Է�: ");
		scanf("%d", &b);
		printf("���� �Է�:");
		scanf("%d", &c);
		area = (a + b) * c * 0.5;
		printf("������ %d�̰� �Ʒ����� %d ���̰� %d�� ��ٸ����� ���̴� %.3f\n", a, b, c, area);
	}

	
}







//------------------�������� ����------------------

/*int a;
	int b;
	int c, d;
	int result;*/
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


		/*printf("ù ��° ����� ���� �Է��ϼ��� ==>");
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
		 */


		 /*printf("%d / %d = %d", 100, 200, 0.5);
		 printf("\n");
		 printf("100�� 16������ ǥ��: %x / 200�� 8������ ǥ�� %o", 100, 200);
		 printf("\n");
		 printf("���� : %d �Ǽ� : %f", 10, 3.14);
		 printf("���̴� %d Ű�� %1.f\n", 25, 175.5);*/

		 /*printf("���� ��: %d", 10);
		 printf("ù ��° ����: %d,  �� ��° ����: %d\n", 5, 20);
		 printf("���ϱ�: %d + %d = %d\n", 15, 4, 15 + 4);
		 printf("���� : %d - %d = %d\n", 15, 4, 11);
		 printf("���ϱ�: %d * %d = %d\n", 15, 4, 15 * 4);
		 printf("������(��) %d / %d = %d\n", 15, 4, 15 / 4);
		 printf("������ %d %% %d = %d\n", 15, 4, 15 % 4);
		 printf("|%10d|\n", 42);
		 printf("|%10d|\n", 1234);
		 printf("|%10d|\n", 7);
		 printf("|%-10d|\n", 42);
		 printf("|%-10d|\n", 1234);
		 printf("|%-10d|\n", 7);*/



		 /*int a,sum;
			 float b,fsum;
			 a = 123.45;
			 b = 200;
			 sum = a + b;
			 fsum = a + b;

			 printf("a�� : %d\n", a);
			 printf("b�� : %f\n", b);
			 printf("������ �� : %d\n", sum);
			 printf("�Ǽ��� �� : %f\n", fsum);*/


			 /*int a, b, c, d;

			 a = 100 + 100;
			 b = a + 100;
			 c = a + b - 100;
			 d = a + b + c;
			 printf("a,b,c,d�� �� == > %d %d %d %d \n", a, b, c, d);

			 a = b = c = d = 100;
			 printf("a,b,c,d�� �� == > %d %d %d %d \n", a, b, c, d);

			 a = 100;
			 a = a + 200;
			 printf("a�� �� ==> %d \n",a);*/






//----��Ģ���� �Է� ����-----

//int first, second, result;
//	char op;
//
//	printf("ù ��° �� �Է� : ");
//	scanf("%d", &first);
//
//	printf("�� ��° �� �Է� : ");
//	scanf("%d", &second);
//
//	printf("+,-,*,/,%%�� ����: ");
//	scanf(" %c", &op);
//
//	if (op == '+') {
//		result = first + second;
//		printf("�� ���� ���� �� : %d\n", result);
//	}
//	else if (op == '-') {
//		result = first - second;
//		printf("�� ���� �� �� : %d\n", result);
//	}
//	else if (op == '*') {
//		result = first * second;
//		printf("�� ���� ���� �� : %d\n", result);
//	}
//	else if (op == '/') {
//		if (second == 0) {
//			printf("�� ��° ���� 0�̹Ƿ� ���� �� �����ϴ�.\n");
//		}
//		else if(first < second){
//			printf("������ ���� 0�Դϴ�.");
//		}
//		else {
//			result = first / second;
//			printf("�� ���� ���� �� : %d\n", result);
//		}
//	}
//	else if (op == '%') {
//		if (second == 0) {
//			printf("�� ��° ���� 0�̹Ƿ� ������ ������ ������ �� �����ϴ�.\n");
//		}
//		else {
//			result = first % second;
//			printf("�� ���� �������� : %d\n", result);
//		}
//	}
//	else {
//		printf("�ùٸ� �����ڸ� �Է��ϼ���.\n");
//	}
//	if (first == second) {
//		printf("�� ���� ���� �����ϴ�.\n");
//	}
//	if (first > second) {
//		printf("ù ��° ���� �� Ů�ϴ�.\n");
//	}
//	if(first < second) {
//		printf("�� ��° ���� �� Ů�ϴ�.\n");
//	}*/