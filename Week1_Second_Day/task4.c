#include <stdio.h>

// 写一个程序测试 && / || / ! 的短路特性

int main()
{
    int num1 = 1;
    int num2 = 0;

    // && 只有双方都为真的时候才会输出真
    printf("1 && 1 = %d\n", num1 && num1);
    printf("0 && 1 = %d\n", num2 && num1);
    printf("1 && 0 = %d\n", num1 && num2);
    printf("0 && 0 = %d\n", num2 && num2);
    printf("\n");

    // || 只有双方都为假的时候才会输出假
    printf("1 || 1 = %d\n", num1 || num1);
    printf("0 || 1 = %d\n", num2 || num1);
    printf("1 || 0 = %d\n", num1 || num2);
    printf("0 || 0 = %d\n", num2 || num2);
    printf("\n");

    // ！ 为反转 
    printf(" !1 = %d\n", !num1);
    printf(" !0 = %d\n", !num2);
    printf("\n");
    
    return 0;
}