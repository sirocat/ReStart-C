#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main() {
	char str[10] = "";
	printf("문자열 입력 : ");
	scanf("%s", str);
	printf("입력된 문자열 : %s\n", str);

	int len = strlen(str);
	for (int i = sizeof(str)-1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");


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


