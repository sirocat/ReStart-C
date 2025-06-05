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
	printf("실수형 result a정수형/실수형 %f", result);*/


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
	printf("b출력 %c\n", b);
	printf("c출력 %c\n", c);
	c = 90;
	printf("코드값 90인 문자 c출력 %c\n", c);*/


	//int a, b;
		//char c, d;
		//a = 0x41;
		//b = 0x50;

		//printf("16진수 0x41 코드 %c\n", a);
		//c = a; // c = 0x41
		//printf("16진수 0x41 코드 %c\n", c);
		//d = '#';
		//printf(" %c의 ASCII값은 %d입니다.", d, d);


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


	printf("입력진수 결정 <1>10진수 <2>16진수 <3>8진수 : ");
		scanf("%d", &type);
		printf("선택한 진수 : %d \n", type);
		if (type == 1) {
			printf("값 입력 : ");
			scanf("%d", &data);
		}
		if (type == 2) {
			printf("값 입력 : ");
			scanf("%x", &data);
		}
		if (type == 3) {
			printf("값 입력 : ");
			scanf("%o", &data);
		}
		printf(" 10진수 : %d \n", data);
		printf(" 16진수 : %x \n",data);
		printf(" 8진수 : %o \n", data);*/



		/*char str[10] = "";
			printf("문자열 입력 : ");
			scanf("%s", str);
			printf("입력된 문자열 : %s\n", str);

			int len = strlen(str);
			for (int i = sizeof(str)-1; i >= 0; i--) {
				printf("%c", str[i]);
			}
			printf("\n");*/



			/*int a = 10;

				a += 3;
				printf("%d\n", a);
				printf("pirntf에서 a 값이 13인 a+=3 실행결과 %d\n", a += 3);
				a++;
				printf("++연산 후 실행 결과 %d\n", a);
				printf("printf에서 ++연산 후 실행 결과 %d\n", a++);
				printf("printf에서 ++연산 후 실행 결과 %d\n", a);
				a = 10;
				++a;
				printf("++연산 후 실행 결과 %d\n", a);
				printf("printf에서 ++연산 후 실행 결과 %d\n", ++a);
				printf("printf에서 ++연산 후 실행 결과 %d\n", a);*/


				//int a = 100, b = 200;

				//printf("%d == %d는 %d이다\n", a, b, a == b); //0
				//printf("%d != %d는 %d이다\n", a, b, a != b); //1
				//printf("%d > %d는 %d이다\n", a, b, a > b); //0
				//printf("%d < %d는 %d이다\n", a, b, a < b); //1
				//printf("%d >= %d는 %d이다\n", a, b, a >= b); //0
				//printf("%d <= %d는 %d이다\n", a, b, a <= b); //1

				//printf("%d = %d는 %d이다\n", a, b, a = b); //200


/*int a = 99;
	printf("AND연산 : %d \n", (a >= 100) && (a <= 200));
	printf("OR연산 : %d\n", (a >= 100) || (a <= 200));
	printf("NOT연산 : %d\n", !(a == 100));*/



	/*int a = 100, b = 200,c=0;
		printf("상수의 and 연산 %d\n", a && b);
		printf("상수의 or 연산 %d\n", a || b);
		printf("상수의 not 연산 %d\n", !a );
		printf("상수(0포함)의 and 연산 %d\n", a && c);*/

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
		printf("%d를 왼쪽으로 시프트 1회 %d\n", a, a << 1);
		printf("%d를 왼쪽으로 시프트 2회 %d\n", a, a << 2);
		printf("%d를 왼쪽으로 시프트 3회 %d\n", a, a << 3);
		printf("%d를 왼쪽으로 시프트 1회 %d\n", a, a >> 1);
		printf("%d를 왼쪽으로 시프트 2회 %d\n", a, a >> 2);
		printf("%d를 왼쪽으로 시프트 3회 %d\n", a, a >> 3);*/



		//int year;

		//printf("년도를 입력하세요 :");
		//scanf("%d", &year);

		//if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		//	printf("%d년은 윤년입니다. \n", year);
		//else
		//	printf("%d년은 윤년이 아닙니다. \n", year);


//int a = 200;
//if (a < 100) {
//	printf("100보다 작군요..\n");
//	printf("거짓이므로 이 문장은 안 보여요\n");
//}
//
//
//printf("프로그램 끝");



/*int jumsu = 0;
	scanf("%d", &jumsu);

	if (jumsu >=90) {
		printf("A입니다\n");
	}
	else if (jumsu >= 80) {
		printf("B입니다\n");
	}
	else if (jumsu >= 70) {
		printf("C입니다\n");
	}
	else if (jumsu >= 60) {
		printf("D입니다\n");
	}
	else {
		printf("F입니다\n");
	}*/

	/*int a,b;
		char op;

		printf("원하는 연산자 입력 (+,-,*,%,/) : ");
		scanf("%c", &op);

		printf("첫 번째 숫자 입력: ");
		scanf("%d", &a);

		printf("두 번째 숫자 입력: ");
		scanf("%d", &b);


		switch (op)
		{
		case '+': printf("결과: %d\n", a + b); break;
		case '-': printf("결과: %d\n", a - b); break;
		case '*': printf("결과: %d\n", a * b); break;
		case '/':
			if (b != 0)
				printf("결과: %.2f\n", (float)a / b);
			else
				printf("0으로 나눌 수 없습니다.\n");
			break;
		case '%':
			if (b != 0)
				printf("결과: %d\n", a % b);
			else
				printf("0으로 나눌 수 없습니다.\n");
			break;
		default: printf("잘못된 연산자입니다.\n"); break;
		}*/