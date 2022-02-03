#include <stdio.h>
// & 
// | 
// ! 
// << 
// >> 
// ~取反 
// ^异或
int rolInt(int inputBits, int n)
{
    int lowBits = inputBits >> (32 - n);
    int highBits = inputBits << n;
    int outputBits = highBits | lowBits;
    return outputBits;
}
int main(int argc, char **argv)
{
    // 以32位数据的循环左移为例
    // 左移n位
    int n = 3;
    int inputBits = 1;
    int lowBits = inputBits >> (32 - n);
    int highBits = inputBits << n;
    int outputBits = highBits | lowBits;

    // 1 -> 8
    printf("%d\n",rolInt(1, 3));
    // -1 -> -1
    printf("%d\n",rolInt(-1,3));
    // 1<<32-3 -> 负数
    printf("%d\n",rolInt(1<<(32-4), 3));
    return 0;
}