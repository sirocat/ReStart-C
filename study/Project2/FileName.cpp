#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main()

{
    int lines;
    int i = 1;

    printf("출력할 줄 수를 입력하시오 : ");
    scanf_s("%d", &lines);

       while (i <= lines) {
           int j = 1;
           while(j <= i){
               printf("*");
               j++;
           }
       printf("\n");
           i++;
       }
}