#include <stdio.h>

/*
3. 用函数指针实现一个简单的"跳转表"：
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int main() {
    int (*ops[])(int, int) = {add, sub, mul};
    printf("%d\n", ops[0](3, 2));  // 5
    printf("%d\n", ops[1](3, 2));  // 1
    printf("%d\n", ops[2](3, 2));  // 6
}
*/

int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}
int mul(int a, int b) {return a * b;}
int main()
{   
    // ops[]这个是数组，每个元素都是int *(int, int)
    int (*ops[])(int, int) = {add, sub, mul};
    printf("%d\n", ops[0](3, 2));
    printf("%d\n", ops[1](3, 2));
    printf("%d\n", ops[2](3, 2));
    return 0;
}