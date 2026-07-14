#include <stdio.h>

/*
2. 写代码演示：
int a[5] 中 &a 和 a 和 &a[0] 的值相同，但加 1 后结果不同
int a[5] = {0};
printf("a = %p\n", a);        // 地址
printf("a+1 = %p\n", a+1);    // 差 4 字节
printf("&a = %p\n", &a);
printf("&a+1 = %p\n", &a+1);  // 差 20 字节（整个数组大小）
*/

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    printf("a address is %p\n", a);
    printf("a + 1 address is %p\n", a + 1);

    // 这个是整个数组的地址，而不是数组第一个元素的地址
    printf("&a address is %p\n", &a);
    printf("&a + 1 address is %p\n", &a + 1);
    return 0;
}