#include <stdio.h>

// 写一个程序测试 ++i 和 i++ 的区别
/*
    ++i 他是先加再输出
    i++ 他是新输出再进行加法
*/
int main()
{
    int a = 1;
    int b = 1;
    printf("%d, %d\n", a++, ++b);
    printf("%d, %d", a, b);
}