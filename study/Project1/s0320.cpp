#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {

	int a, b, c, choice;
	float area;

	printf("<1> 삼각형 <2>사각형 <3>원 <4>사다리꼴 ");
	scanf("%d", &choice);
	if (choice == 1) {
		printf("밑변의 길이 입력: ");
		scanf("%d", &a);
		printf("높이 입력: ");
		scanf("%d", &b);
		area = a * b * 0.5;
		printf("밑변이 %d이고 높이가 %d인 삼각형의 넓이는 : %3.f\n", a, b, area);
	}
	if (choice == 2) {
		printf("가로 길이 입력: ");
		scanf("%d", &a);
		printf("세로 길이 입력: ");
		scanf("%d", &b);
		area = a * b;
		printf("가로 길이 %d 세로 길이 %d인 사각형의 넓이는 : %.3f\n",a,b, area);
	}
	if (choice == 3) {
		printf("반지름의 길이 입력: ");
		scanf("%d", &a);
		area = a * a * 3.14;
		printf("반지름의 길이가 %d인 원의 넓이는 : %.3f\n", a, area);
	}
	if (choice == 4) {
		printf("윗변의 넓이 입력: ");
		scanf("%d", &a);
		printf("아랫변의 넓이 입력: ");
		scanf("%d", &b);
		printf("높이 입력:");
		scanf("%d", &c);
		area = (a + b) * c * 0.5;
		printf("윗변이 %d이고 아랫변이 %d 높이가 %d인 사다리꼴의 넓이는 %.3f\n", a, b, c, area);
	}

	
}







//------------------변수선언 예제------------------

/*int a;
	int b;
	int c, d;
	int result;*/
	/*a = 100;
	b = 200;
	result = a + b;
	printf("Hello world\n");
	printf("a에 저장된 값 : %d \nb에 저장된 값 : %d\n",a,b);
	printf("%d + %d = %d\n",a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);
	printf("%d\n", result);*/
	/*scanf("%d", &a);
	scanf("%d", &b);
	printf("첫 번째 읽어들인 값은 : %d\n", a);
	printf("두 번째 읽어들인 값은 : %d\n", b);
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);

	if (a == 0 || b == 0) {
		printf("곱하기를 계산할 수 없습니다.\n");
		printf("나누기를 계산할 수 없습니다.\n");
	}else{
		printf("%d * %d = %d\n", a, b, a * b);
		printf("%d / %d = %d\n", a, b, a / b);
	}*/
	/*if (b != 0) {
		printf("%d / %d = %d\n", a, b, a / b);
	}*/
	/*printf("첫 번째 계산할 값을 입력하세요 ==>");
	scanf("%d", &a);
	printf("두 번째 계산할 값을 입력하세요 ==>");
	scanf("%d", &b);
	printf("세 번째 계산할 값을 입력하세요 ==>");
	scanf("%d", &c);
	printf("네 번째 계산할 값을 입력하세요 ==>");
	scanf("%d", &d);
	printf("%d + %d + %d + %d = %d", a, b, c, d, a + b + c + d);*/

	/*scanf("%d", &a);
	scanf("%d", &b);
	q
	if (a > b)
		printf("a가 %d만큼 큽니다", a - b);
	else if(b == a)
		printf("두 값이 같습니다.");
	else
		printf("b가 %d만큼 큽니다", b - a);*/


		/*printf("첫 번째 계산할 값을 입력하세요 ==>");
		scanf("%d", &a);
		printf("<1>덧셈 <2>뺄셈 <3>곱셈 <4>나눗셈 <5>나머지 ==>");
		scanf("%d", &b);
		printf("두 번째 계산할 값을 입력하세요 ==>");
		scanf("%d", &c);
		if (b == 1) {
			printf("%d + %d = %d", a, c, a + c);
		}
		else if (b == 2) {
			printf("%d - %d = %d", a, c, a - c);
		}
		else if (b == 3) {
			if (c == 0) {
				printf("계산할 수 없습니다.");
			}
			else {
				printf("%d * %d = %d", a, c, a * c);
			}
		}
		else if (b == 4) {
			if (c==0) {
				printf("계산할 수 없습니다.");
			}
			else {
				printf("%d / %d = %.2f", a, c, (float)a / c);
			}
		}
		else if (b == 5) {
			print("%d % %d = %.2f",a,c,(float)a%c)
		}
		else{
			printf("없는 조건입니다");
		}
		 */


		 /*printf("%d / %d = %d", 100, 200, 0.5);
		 printf("\n");
		 printf("100을 16진수로 표현: %x / 200을 8진수로 표현 %o", 100, 200);
		 printf("\n");
		 printf("정수 : %d 실수 : %f", 10, 3.14);
		 printf("나이는 %d 키는 %1.f\n", 25, 175.5);*/

		 /*printf("정수 값: %d", 10);
		 printf("첫 번째 정수: %d,  두 번째 정수: %d\n", 5, 20);
		 printf("더하기: %d + %d = %d\n", 15, 4, 15 + 4);
		 printf("빼기 : %d - %d = %d\n", 15, 4, 11);
		 printf("곱하기: %d * %d = %d\n", 15, 4, 15 * 4);
		 printf("나누기(몫) %d / %d = %d\n", 15, 4, 15 / 4);
		 printf("나머지 %d %% %d = %d\n", 15, 4, 15 % 4);
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

			 printf("a값 : %d\n", a);
			 printf("b값 : %f\n", b);
			 printf("정수형 합 : %d\n", sum);
			 printf("실수형 합 : %f\n", fsum);*/


			 /*int a, b, c, d;

			 a = 100 + 100;
			 b = a + 100;
			 c = a + b - 100;
			 d = a + b + c;
			 printf("a,b,c,d의 값 == > %d %d %d %d \n", a, b, c, d);

			 a = b = c = d = 100;
			 printf("a,b,c,d의 값 == > %d %d %d %d \n", a, b, c, d);

			 a = 100;
			 a = a + 200;
			 printf("a의 값 ==> %d \n",a);*/






//----사칙연산 입력 예제-----

//int first, second, result;
//	char op;
//
//	printf("첫 번째 수 입력 : ");
//	scanf("%d", &first);
//
//	printf("두 번째 수 입력 : ");
//	scanf("%d", &second);
//
//	printf("+,-,*,/,%%중 선택: ");
//	scanf(" %c", &op);
//
//	if (op == '+') {
//		result = first + second;
//		printf("두 값을 더한 값 : %d\n", result);
//	}
//	else if (op == '-') {
//		result = first - second;
//		printf("두 값을 뺀 값 : %d\n", result);
//	}
//	else if (op == '*') {
//		result = first * second;
//		printf("두 값을 곱한 값 : %d\n", result);
//	}
//	else if (op == '/') {
//		if (second == 0) {
//			printf("두 번째 수가 0이므로 나눌 수 없습니다.\n");
//		}
//		else if(first < second){
//			printf("나누기 값이 0입니다.");
//		}
//		else {
//			result = first / second;
//			printf("두 값을 나눈 값 : %d\n", result);
//		}
//	}
//	else if (op == '%') {
//		if (second == 0) {
//			printf("두 번째 수가 0이므로 나머지 연산을 수행할 수 없습니다.\n");
//		}
//		else {
//			result = first % second;
//			printf("두 값의 나머지는 : %d\n", result);
//		}
//	}
//	else {
//		printf("올바른 연산자를 입력하세요.\n");
//	}
//	if (first == second) {
//		printf("두 수의 값이 같습니다.\n");
//	}
//	if (first > second) {
//		printf("첫 번째 값이 더 큽니다.\n");
//	}
//	if(first < second) {
//		printf("두 번째 값이 더 큽니다.\n");
//	}*/