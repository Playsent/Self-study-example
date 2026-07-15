#include <stdio.h>
#include <stdlib.h>   // 如果使用 qsort（此处排序改用冒泡，可不加）



// ==================== 1. Student 结构体定义与排序 ====================
typedef struct {
    char name[20];
    int age;
    float score;
} Student;

// 交换两个 Student 结构体
void swap_student(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// 按 score 降序排序（冒泡排序，使用交换函数）
void sort_by_score(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].score < arr[j + 1].score) {
                swap_student(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 打印学生数组
void print_students(Student arr[], int n, const char *title) {
    printf("%s\n", title);
    printf("%-10s %-4s %-6s\n", "Name", "Age", "Score");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-4d %-6.1f\n", arr[i].name, arr[i].age, arr[i].score);
    }
    printf("\n");
}

// ==================== 2. 结构体对齐验证 ====================
// 默认对齐的结构体
struct A {
    char a;
    int b;
    char c;
};

struct B {
    char a;
    char c;
    int b;
};

// 紧凑（取消对齐）的结构体
struct A_packed {
    char a;
    int b;
    char c;
} __attribute__((packed));

struct B_packed {
    char a;
    char c;
    int b;
} __attribute__((packed));

void check_alignment() {
    printf("===== 结构体对齐验证 =====\n");
    printf("默认对齐（通常 4 字节对齐）：\n");
    printf("struct A (char,int,char): %zu 字节\n", sizeof(struct A));
    printf("struct B (char,char,int): %zu 字节\n", sizeof(struct B));
    printf("packed A: %zu 字节\n", sizeof(struct A_packed));
    printf("packed B: %zu 字节\n", sizeof(struct B_packed));
    printf("\nstruct A 内存布局（默认对齐，假设 4 字节对齐）：\n");
    printf("偏移 0: a (1字节)\n");
    printf("偏移 1~3: 填充 (3字节)\n");
    printf("偏移 4~7: b (4字节)\n");
    printf("偏移 8: c (1字节)\n");
    printf("偏移 9~11: 填充 (3字节) → 总大小 12 字节\n\n");
}

// ==================== 3. 联合体验证大小端 ====================
void check_endian() {
    printf("===== 大小端检测 =====\n");
    union {
        int a;
        char b;
    } u;
    u.a = 0x12345678;
    printf("u.a = 0x%x\n", u.a);
    printf("u.b = 0x%x\n", u.b);
    if (u.b == 0x78) {
        printf("结果：当前机器为 **小端模式**（低位字节在低地址）\n");
    } else if (u.b == 0x12) {
        printf("结果：当前机器为 **大端模式**（高位字节在低地址）\n");
    } else {
        printf("结果：未知模式\n");
    }
    printf("\n");
}

// ==================== 4. 关键字验证 ====================
// --- static ---
static int global_static = 100;   // 静态全局变量，仅本文件可见

void func_with_static() {
    static int local_static = 0;  // 静态局部变量，保持状态
    local_static++;
    printf("    调用 func_with_static，local_static = %d\n", local_static);
}

// --- const 验证 ---
void check_const() {
    int x = 10, y = 20;

    // 1. 指向的内容不能改，指针可变
    const int *p1 = &x;
    // *p1 = 30;          // 编译错误
    p1 = &y;              // 允许
    printf("    const int *p1:  *p1=%d (指针可变, 指向的值只读)\n", *p1);

    // 2. 指针本身不能改，指向的内容可变
    int * const p2 = &x;
    *p2 = 50;             // 允许
    // p2 = &y;           // 编译错误
    printf("    int * const p2:  *p2=%d (指针不可变, 值可改)\n", *p2);

    // 3. 都不能改
    const int * const p3 = &x;
    // *p3 = 60;          // 编译错误
    // p3 = &y;           // 编译错误
    printf("    const int * const p3:  *p3=%d (指针和值都不可改)\n", *p3);
}

// --- volatile ---
void check_volatile() {
    volatile int flag = 0;  // 每次从内存读取
    // 简单演示：即使编译器优化，也不会把 while 优化掉
    int counter = 0;
    while (flag == 0) {
        counter++;
        if (counter > 5) break;   // 避免死循环，仅展示语法
    }
    printf("    volatile int flag 避免了死循环优化，counter=%d\n", counter);
}

// ==================== 主函数 ====================
int main() {
    printf("==================== 综合验证程序 ====================\n\n");

    // ---------- 1. 学生排序 ----------
    Student students[] = {
        {"Alice",   20, 88.5},
        {"Bob",     22, 92.0},
        {"Charlie", 19, 78.0},
        {"David",   21, 85.5},
        {"Eve",     20, 92.0}
    };
    int n = sizeof(students) / sizeof(students[0]);

    print_students(students, n, "原始顺序：");
    sort_by_score(students, n);
    print_students(students, n, "按 score 降序排序后：");

    // ---------- 2. 对齐验证 ----------
    check_alignment();

    // ---------- 3. 大小端检测 ----------
    check_endian();

    // ---------- 4. 关键字演示 ----------
    printf("===== 关键字验证 =====\n");

    // static
    printf("[static]\n");
    printf("    全局静态变量 global_static = %d (仅本文件可见)\n", global_static);
    for (int i = 0; i < 3; i++) {
        func_with_static();  // 每次调用 local_static 累加
    }

    // const
    printf("\n[const]\n");
    check_const();

    // volatile
    printf("\n[volatile]\n");
    check_volatile();

    printf("\n==================== 验证结束 ====================\n");
    return 0;
}