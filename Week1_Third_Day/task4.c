#include <stdio.h>

// 写一个程序：用 switch-case 实现一个简易计算器（+ - * /）

int switch_case(int num1, int num2, char str1)
{
    int res = 0;
    if(str1 == '+')
    {
        return num1 + num2;
    }
    if(str1 == '-')
    {
        return num1 - num2;
    }
    if(str1 == '*')
    {
        return num1 * num2;
    }
    if(str1 == '/')
    {
        return num1 / num2;
    }
}



int main()
{
    int num1, num2;
    char str1;
    scanf("%d %d %c", &num1, &num2, &str1);
    printf("%d %c %d = %d\n", num1, str1, num2, switch_case(num1, num2, str1));
    return 0;
}