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


	printf("첫 번째 계산할 값을 입력하세요 ==>");
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
	                            
}