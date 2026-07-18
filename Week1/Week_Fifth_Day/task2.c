#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2.  写一个交换函数，按 score 排序    
    验证结构体对齐规则：
    定义一个结构体，成员顺序影响大小，用 sizeof 验证
    struct A { char a; int b; char c; };   // 猜多大？
    struct B { char a; char c; int b; };   // 猜多大？
    用 __attribute__((packed)) 再试一次
    __attribute__((packed)): 告诉编译器不要插入任何填充字节，成员紧密排列，总大小即为各成员大小之和
    结构体成员的存放规则： 
    规律：
        <1>结构体成员的相对偏移[成员偏移结构体首地址的字节数] % 本身位置偏移 == 0, 不满足则补齐，直到可以为0 
        相对偏移：指的是现阶段结构体的偏移量， 本身偏移：指的是马上要插入的元素的自己的偏移量
        偏移量：char:1 / short:2 / int:4 / long:4 / float:4 / double:4 
        <2>最后结构体总大小 % 最大成员的位置偏移 == 0,不满足则补齐，直到可以为0 
        注：不遵从规则需要补齐，直到满足我们的上述关系位置
*/

typedef struct 
{
    char name[20];
    int age;
    float score;
} Student;

struct A
{
    char a;
    int b;
    char c;
};

struct B 
{
    char a;
    int b;
    char c;
};

struct A_packed 
{
    char a;
    int b;
    char c;
} __attribute__((packed));

struct B_packed 
{
    char a;
    char c;
    int b;
} __attribute__((packed));

void Sort_by_score(Student arr[], int n)
{
    //对成绩进行降序冒泡排序
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j].score < arr[j + 1].score)
            {
                Student temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    //对成绩进行初始化
    Student students[] = 
    {
        {"Ailce", 20, 88.5},
        {"Bob", 22, 92},
        {"Charile", 19, 78},
        {"David", 21, 85.5},
        {"Eve", 20, 92}
    };
    int n = sizeof(students) / sizeof(students[0]);
    Sort_by_score(students, n);

    // 对成绩进行输出
    printf("将成绩进行降序排序：\n");
    for(int i = 0; i < n; i++) printf("%-10s score is %-4.2f\n", students[i].name, students[i].score);

    // -------------------------------------结构体的对齐验证-------------------------------------
    printf("\n===== 结构体对齐验证 =====\n");
    printf("struct A (char,int,char): %d 字节\n", sizeof(struct A));
    printf("struct B (char,char,int): %d 字节\n", sizeof(struct B));
    printf("packed A: %d 字节\n", sizeof(struct A_packed));
    printf("packed B: %d 字节\n", sizeof(struct B_packed));

    return 0;
}