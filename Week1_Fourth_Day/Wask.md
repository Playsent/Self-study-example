Day 4（7/14）— 指针专题（最重要的半天）
具体任务

1. 写代码区分以下 4 种指针： （已完成）
int *p;           // 指向整数的指针
int *arr[5];      // 指针数组（数组里存了5个指针）
int (*p)[5];      // 数组指针（指向包含5个整数的数组）
int (*fp)(int);   // 函数指针

2. 写代码演示：int a[5] 中 &a 和 a 和 &a[0] 的值相同，但加 1 后结果不同 （已完成）
int a[5] = {0};
printf("a = %p\n", a);        // 地址
printf("a+1 = %p\n", a+1);    // 差 4 字节
printf("&a = %p\n", &a);
printf("&a+1 = %p\n", &a+1);  // 差 20 字节（整个数组大小）

3. 用函数指针实现一个简单的"跳转表"： （已完成）
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int main() {
    int (*ops[])(int, int) = {add, sub, mul};
    printf("%d\n", ops[0](3, 2));  // 5
    printf("%d\n", ops[1](3, 2));  // 1
    printf("%d\n", ops[2](3, 2));  // 6
}
验收标准：能口述 指针数组 和 数组指针 的区别 + 能写出函数指针做回调的例子。