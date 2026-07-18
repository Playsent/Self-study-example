#include <stdio.h>
// 2. 写一个程序演示原码/反码/补码：给一个负数，手动用位运算打印它的补码

// 打印bits位的二进制形式(最高位在左)
void printf_binary(unsigned char num, int bits)
{
    for(int i = bits - 1; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
}

int main()
{
    int input;
    printf("请输入一个负数(-1到-128): ");
    scanf("%d", &input);

    if(input >= 0 || input < -128)
    {
        printf("输入不合适，请输入合适范围内的负数。\n");
        return -1;
    }

    int bits = 8;
    int abs_val = -input;

    // 这个是原码               10000000 | abs_val
    unsigned char original = (1 << (bits - 1)) | abs_val;

    // 这个是反码               0111 1111
    unsigned char mask = (1 <<(bits - 1)) - 1;
    //              例子：1111 1111 ^ 0111 1111
    unsigned char inverse = original ^ mask;

    // 这个是补码
    unsigned char complement = inverse + 1; 
    
    printf("输入的十进制: %d\n", input);
    printf("原码: ");
    printf_binary(original, bits);
    printf("\n");

    printf("反码: ");
    printf_binary(inverse, bits);
    printf("\n");

    printf("补码: ");
    printf_binary(complement, bits);
    printf("\n");

    // 进行验证: 直接打印数据的补码(有符号的数据类型基本上都是使用补码进行储存的)
    signed char machine = (signed char)input;
    printf("机器实际储存的补码：   ");
    printf_binary((unsigned char)machine, bits);

    return 0;
}