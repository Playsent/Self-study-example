#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 创建新节点
Node *Create_Node(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (NULL == p) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->data = data;
    p->next = NULL;
    return p;
}

// 头插法（需要修改头指针，用二级指针）
void Insert_Head(Node **head, int data) {
    Node *p = Create_Node(data);
    p->next = *head;
    *head = p;
}

// 尾插法（需要处理空链表情况）
void Insert_Tail(Node **head, int data) {
    Node *p = Create_Node(data);
    if (*head == NULL) {
        *head = p;
        return;
    }
    Node *cur = *head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = p;
}

// 删除指定值（删除第一个匹配的节点）
void Delete_Node(Node **head, int data) {
    if (*head == NULL) return;

    Node *cur = *head;
    Node *prev = NULL;

    // 如果要删除的是头节点
    if (cur->data == data) {
        *head = cur->next;
        free(cur);
        printf("删除%d成功\n", data);
        return;
    }

    // 查找要删除的节点
    while (cur != NULL && cur->data != data) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("链表内没有需要删除的数据\n");
        return;
    }

    prev->next = cur->next;
    free(cur);
    printf("删除%d成功\n", data);
}

// 遍历打印
void Printf_Node(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// 迭代反转
Node *Reverse_Iter(Node *head) {
    Node *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

// 递归反转
Node *Reverse_Recursive(Node *head) {
    if (!head || !head->next) return head;   // 修正退出条件
    Node *new_head = Reverse_Recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main() {
    Node *head = NULL;

    // 尾插 1,2,3
    Insert_Tail(&head, 1);
    Insert_Tail(&head, 2);
    Insert_Tail(&head, 3);
    printf("After tail inserts: ");
    Printf_Node(head);

    // 头插 0
    Insert_Head(&head, 0);
    printf("After head insert 0: ");
    Printf_Node(head);

    // 删除 2
    Delete_Node(&head, 2);
    printf("After delete 2: ");
    Printf_Node(head);

    // 迭代反转
    head = Reverse_Iter(head);
    printf("After iterative reverse: ");
    Printf_Node(head);

    // 递归反转
    head = Reverse_Recursive(head);
    printf("After recursive reverse: ");
    Printf_Node(head);

    // 释放内存
    Node *cur = head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    return 0;
}