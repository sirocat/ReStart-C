#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main()

{
    int lines;
    int i = 1;

    printf("����� �� ���� �Է��Ͻÿ� : ");
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