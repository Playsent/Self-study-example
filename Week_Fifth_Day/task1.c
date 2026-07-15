#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
1.  定义结构体 Student，包含 name、age、score，创建数组并排序
    typedef struct {
        char name[20];
        int age;
        float score;
    } Student;
*/
typedef struct 
{
    char name[20];
    int age;
    float score;
} Student;

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

    //对成绩进行冒泡排序
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(students[j].score > students[j + 1].score)
            {
                Student temp;
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    //对排序后的结构体进行输出
    for(int i = 0; i < n; i++)
    {
        printf("%s Score is %f\n", students[i].name, students[i].score);
    }
    return 0;
}