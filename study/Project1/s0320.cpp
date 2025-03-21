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

	printf("정수 값: %d", 10);
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
	printf("|%-10d|\n", 7);
	


}