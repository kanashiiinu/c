#include <stdio.h>
#include <stdbool.h>
union BaseType
{
    bool b;
    int i;
    float f;
    double d;
    char c;
    char * cstr;
};


int main(int argc, char **argv)
{
    union BaseType baseType;
    baseType.b = true;
    printf("now is %d\n",baseType.b);
    baseType.i = 10;
    printf("now is %d\n",baseType.i);
    baseType.f = 1.7f;
    printf("now is %f\n",baseType.f);
    baseType.d = 3.8;
    printf("now is %f\n",baseType.d);
    baseType.c = 'e';
    printf("now is %c\n",baseType.c);
    baseType.cstr = "hello";
    printf("now is %s\n",baseType.cstr);
    printf("sizeof union is : %d\n",sizeof(baseType));
    return 0;
}