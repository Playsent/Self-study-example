#include <stdio.h>

// 写一个程序：for 循环打印 9×9 乘法表

int main()
{
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%d * %d = %d ", j, i, j * i);
        }
        printf("\n");
    }
    return 0;
}