#include <stdio.h>
struct stauts
{
    unsigned sign:1;
    unsigned zero:1;
    unsigned carry:1;
    unsigned parity:1;
    unsigned half_carry:1;
    unsigned negative:1;
    unsigned unused:30;
};
int main(int argc, char **argv)
{
    struct stauts s;
    int i;
    s.carry = 0;
    printf("%d\n",sizeof(s));
    printf("%d\n",s.carry);
    return 0;
}