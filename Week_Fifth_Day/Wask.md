具体任务
1.  定义结构体 Student，包含 name、age、score，创建数组并排序 (已完成)
    typedef struct {
        char name[20];
        int age;
        float score;
    } Student;
2.  // 写一个交换函数，按 score 排序 (已完成)
    验证结构体对齐规则：
    // 定义一个结构体，成员顺序影响大小，用 sizeof 验证
    struct A { char a; int b; char c; };   // 猜多大？
    struct B { char a; char c; int b; };   // 猜多大？
    // 用 __attribute__((packed)) 再试一次
3.  联合体验证大小端：
    union { int a; char b; } u;
    u.a = 0x12345678;
    printf("0x%x\n", u.b);  // 小端输出 0x78，大端输出 0x12
4.  写代码验证每个关键字：(已完成)
    tatic int count = 0;      // 静态全局变量，文件内可见
    void func() {
        static int local = 0;  // 静态局部变量，退出不销毁
        local++;
        printf("%d\n", local);
    }

    const int *p;     // 指向的内容不能改
    int * const p;    // 指针本身不能改
    const int * const p; // 都不能改

    volatile int flag;  // 禁止编译器优化，每次从内存读
    验收标准：能画出 struct A 在内存中的字节排列图 + 能写出 const 的 3 种组合各自含义。