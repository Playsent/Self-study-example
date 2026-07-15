#include <stdio.h>

/*
3.  联合体验证大小端：
    union { int a; char b; } u;
    u.a = 0x12345678;
    printf("0x%x\n", u.b);  // 小端输出 0x78，大端输出 0x12
*/

int main() {
    union 
    {
        int a;
        char b;
    } u;

    u.a = 0x12345678;

    printf("int a   = 0x%x\n", u.a);
    printf("char b  = 0x%x\n", u.b);   // 只读第一个字节
    printf("地址：%p\n", (void*)&u);
    printf("a 的地址：%p\n", (void*)&u.a);
    printf("b 的地址：%p\n", (void*)&u.b);  // 它们地址相同

    // 判断大小端
    if(u.b == 0x78) 
    {
        printf("你的机器是 **小端模式**（低位字节在低地址）\n");
    } 
    else if(u.b == 0x12) 
    {
        printf("你的机器是 **大端模式**（高位字节在低地址）\n");
    }
    else 
    {
        printf("未知模式\n");
    }

    return 0;
}