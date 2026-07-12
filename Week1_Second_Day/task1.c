#include <stdio.h>
// 1. 写一个程序打印每种数据类型的 sizeof（char / short / int / long / float / double / 指针）
int main()
{
    printf("sizeof(char) is : %d\n", sizeof(char));
    printf("sizeof(short) is : %d\n", sizeof(short));
    printf("sizeof(int) is : %d\n", sizeof(int));
    printf("sizeof(float) is : %d\n", sizeof(float));
    printf("sizeof(double) is : %d\n", sizeof(double));
    printf("sizeof(double) is : %d\n", sizeof(double));
    printf("sizeof(int *) is : %d\n", sizeof(int *));
    return 0;
}