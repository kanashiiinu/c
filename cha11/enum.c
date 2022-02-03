#include <stdio.h>
enum Colors{RED, GREEN, BLUE};
int main(int argc, char **argv)
{
    char * colorStr[3] = {"red","green","blue"};
    int colorVal[] = {RED,GREEN,BLUE};
    int i;
    for (i = 0; i < 3;++i) {
        printf("color is %s\n",colorStr[colorVal[i]]);
    }
    return 0;
}