#include <stdio.h>

// 写一个程序：二维数组（3×3），计算对角线元素之和

int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int sum= 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == j || i + j == 2)
            {
                sum += arr[i][j];
            }
        }
    }
    sum -= arr[1][1];
    printf("%d", sum);
    return 0;
}