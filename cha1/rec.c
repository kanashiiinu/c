// #include "stdafx.h"
#include <stdio.h>
#include <stdbool.h>
struct StudentInfo{
    char name[10];
    char address[20];
    char telNum[15];
}info[100];
int main(int argc, char **argv)
{
    printf_s("%d\n",sizeof(bool));
    printf_s("%d\n",sizeof(char));
    printf_s("%d\n",sizeof(float));
    printf_s("%d\n",sizeof(double));
    printf_s("int : %d\n",sizeof(int));
    printf_s("long : %d\n",sizeof(long));
    printf_s("long long : %d\n",sizeof(long long));
    printf_s("%d\n",sizeof(struct StudentInfo));
    return 0;
}