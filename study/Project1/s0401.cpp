#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

void main() {

	
	
	

	
	


}



//printf("%d\n", 123);
//printf("%5d\n", 123);
//printf("%05d\n", 123);
//printf("%f\n", 123.45);
//printf("%7.1f\n", 123.45);
//printf("%7.3f\n", 123.45);
//printf("%s\n", "Basic-C");
//printf("%10s\n", "Basic-C");


	/*int a = 100, b = 200;
	float result;
	result = a / 200.0;
	printf("�Ǽ��� result a������/�Ǽ��� %f", result);*/


//char ch;
//ch = 'a';
//printf("%c\n", ch);
//printf("%d\n", ch);
//ch = 88;
//printf("%c\n", ch);
//printf("%d\n", ch);*/


/*char a, b, c;
	a = 'A';
	printf("%c\n", a);
	printf("%d\n", a);
	b = 'a';
	c = b + 5;
	printf("b��� %c\n", b);
	printf("c��� %c\n", c);
	c = 90;
	printf("�ڵ尪 90�� ���� c��� %c\n", c);*/


	//int a, b;
		//char c, d;
		//a = 0x41;
		//b = 0x50;

		//printf("16���� 0x41 �ڵ� %c\n", a);
		//c = a; // c = 0x41
		//printf("16���� 0x41 �ڵ� %c\n", c);
		//d = '#';
		//printf(" %c�� ASCII���� %d�Դϴ�.", d, d);


/*char str1[10];
	char str2[10];
	char str3[10] = "CookBook";

	printf("%s\n", str3);
	str1[0] = str3[0];
	str1[1] = str3[1];
	str1[2] = str3[2];
	str1[3] = str3[3];
	str1[4] = str3[4];
	str1[5] = str3[5];
	str1[6] = str3[6];
	str1[7] = str3[7];
	str1[8] = str3[8];
	str1[9] = str3[9];
	printf("%s\n", str1);
	strcpy(str2,"Dealim");
	printf("%s\n", str2);
	strcpy(str1, str2);
	printf("%s\n", str1);*/



/*int type,data;


	printf("�Է����� ���� <1>10���� <2>16���� <3>8���� : ");
		scanf("%d", &type);
		printf("������ ���� : %d \n", type);
		if (type == 1) {
			printf("�� �Է� : ");
			scanf("%d", &data);
		}
		if (type == 2) {
			printf("�� �Է� : ");
			scanf("%x", &data);
		}
		if (type == 3) {
			printf("�� �Է� : ");
			scanf("%o", &data);
		}
		printf(" 10���� : %d \n", data);
		printf(" 16���� : %x \n",data);
		printf(" 8���� : %o \n", data);*/



		/*char str[10] = "";
			printf("���ڿ� �Է� : ");
			scanf("%s", str);
			printf("�Էµ� ���ڿ� : %s\n", str);

			int len = strlen(str);
			for (int i = sizeof(str)-1; i >= 0; i--) {
				printf("%c", str[i]);
			}
			printf("\n");*/



			/*int a = 10;

				a += 3;
				printf("%d\n", a);
				printf("pirntf���� a ���� 13�� a+=3 ������ %d\n", a += 3);
				a++;
				printf("++���� �� ���� ��� %d\n", a);
				printf("printf���� ++���� �� ���� ��� %d\n", a++);
				printf("printf���� ++���� �� ���� ��� %d\n", a);
				a = 10;
				++a;
				printf("++���� �� ���� ��� %d\n", a);
				printf("printf���� ++���� �� ���� ��� %d\n", ++a);
				printf("printf���� ++���� �� ���� ��� %d\n", a);*/


				//int a = 100, b = 200;

				//printf("%d == %d�� %d�̴�\n", a, b, a == b); //0
				//printf("%d != %d�� %d�̴�\n", a, b, a != b); //1
				//printf("%d > %d�� %d�̴�\n", a, b, a > b); //0
				//printf("%d < %d�� %d�̴�\n", a, b, a < b); //1
				//printf("%d >= %d�� %d�̴�\n", a, b, a >= b); //0
				//printf("%d <= %d�� %d�̴�\n", a, b, a <= b); //1

				//printf("%d = %d�� %d�̴�\n", a, b, a = b); //200


/*int a = 99;
	printf("AND���� : %d \n", (a >= 100) && (a <= 200));
	printf("OR���� : %d\n", (a >= 100) || (a <= 200));
	printf("NOT���� : %d\n", !(a == 100));*/



	/*int a = 100, b = 200,c=0;
		printf("����� and ���� %d\n", a && b);
		printf("����� or ���� %d\n", a || b);
		printf("����� not ���� %d\n", !a );
		printf("���(0����)�� and ���� %d\n", a && c);*/

		/*char a = 'A', b, c ;
		char mask = 0x0F;

		printf(" %X & %X = %X\n", a, mask, a & mask);
		printf(" %X | %X = %X\n", a, mask, a | mask);

		mask = 'a' - 'A';

		b = a ^ mask;
		printf("%c ^%  = %c \n", a, mask, b);
		a = b ^ mask;
		printf("%c ^ %d = %c\n", b, mask, a);*/

		/*int a = 10;
		printf("%d�� �������� ����Ʈ 1ȸ %d\n", a, a << 1);
		printf("%d�� �������� ����Ʈ 2ȸ %d\n", a, a << 2);
		printf("%d�� �������� ����Ʈ 3ȸ %d\n", a, a << 3);
		printf("%d�� �������� ����Ʈ 1ȸ %d\n", a, a >> 1);
		printf("%d�� �������� ����Ʈ 2ȸ %d\n", a, a >> 2);
		printf("%d�� �������� ����Ʈ 3ȸ %d\n", a, a >> 3);*/



		//int year;

		//printf("�⵵�� �Է��ϼ��� :");
		//scanf("%d", &year);

		//if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		//	printf("%d���� �����Դϴ�. \n", year);
		//else
		//	printf("%d���� ������ �ƴմϴ�. \n", year);


//int a = 200;
//if (a < 100) {
//	printf("100���� �۱���..\n");
//	printf("�����̹Ƿ� �� ������ �� ������\n");
//}
//
//
//printf("���α׷� ��");



/*int jumsu = 0;
	scanf("%d", &jumsu);

	if (jumsu >=90) {
		printf("A�Դϴ�\n");
	}
	else if (jumsu >= 80) {
		printf("B�Դϴ�\n");
	}
	else if (jumsu >= 70) {
		printf("C�Դϴ�\n");
	}
	else if (jumsu >= 60) {
		printf("D�Դϴ�\n");
	}
	else {
		printf("F�Դϴ�\n");
	}*/

	/*int a,b;
		char op;

		printf("���ϴ� ������ �Է� (+,-,*,%,/) : ");
		scanf("%c", &op);

		printf("ù ��° ���� �Է�: ");
		scanf("%d", &a);

		printf("�� ��° ���� �Է�: ");
		scanf("%d", &b);


		switch (op)
		{
		case '+': printf("���: %d\n", a + b); break;
		case '-': printf("���: %d\n", a - b); break;
		case '*': printf("���: %d\n", a * b); break;
		case '/':
			if (b != 0)
				printf("���: %.2f\n", (float)a / b);
			else
				printf("0���� ���� �� �����ϴ�.\n");
			break;
		case '%':
			if (b != 0)
				printf("���: %d\n", a % b);
			else
				printf("0���� ���� �� �����ϴ�.\n");
			break;
		default: printf("�߸��� �������Դϴ�.\n"); break;
		}*/