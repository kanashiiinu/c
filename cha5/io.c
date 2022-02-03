#include <stdio.h>
int main()
{
    printf("%d\n",__STDC_VERSION__);
    putchar('-');
    puts("Enter A\n");
    char inputChar = getchar();
    //回车才算输入，所以输入很多也只取第一个字符，然后后续算下一次输入。
    putchar('\n');
    printf("%c\n", inputChar);
    printf("input a string\n");
    char inputStr[30]; 
    // gets可能缓冲区溢出c11弃用
    // gets_s不知道为什么用不了
    fgets(inputStr,20,stdin);
    printf("output is %s\n",inputStr);
    char * inStr,inStr2;
    scanf("%s",inStr);
    printf("%s\n%s\n",inStr,inStr2);
    return 0;
}