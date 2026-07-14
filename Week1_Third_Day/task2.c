#include <stdio.h>

// 输入一个整数数组，用冒泡排序排序，用 while 循环输出

int main()
{
    int a[10] = {1, 3, 2, 7, 32, 56, 34, 86, 4, 3};
    int len = sizeof(a) / sizeof(a[0]);

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = 0; j < len - 1 - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = 0;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }


    return 0;
}