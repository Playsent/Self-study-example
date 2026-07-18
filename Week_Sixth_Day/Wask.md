Day 6（7/16）— 内存管理 + 链表实战
1.  具体任务
    手写 memcpy 和 memmove（区别在于内存重叠时）：  (已完成)
    void *my_memcpy(void *dst, const void *src, size_t n) {
        char *d = (char *)dst;
        char *s = (char *)src;
        for (size_t i = 0; i < n; i++) d[i] = s[i];
        return dst;
    }

    void* my_memmove(void* dst, const void* src, size_t n) {
        char* d = (char*)dst;
        char* s = (char*)src;
        if (d < s) {
            for (size_t i = 0; i < n; i++) d[i] = s[i];
        } else {
            for (size_t i = n; i > 0; i--) d[i-1] = s[i-1];
        }
        return dst;
    }
2.  手写单链表（包含所有基础操作）：
    typedef struct Node {
        int data;
        struct Node* next;
    } Node;

    // 必须能独立写出这 5 个函数：
    Node* create_node(int data);            // 创建节点
    void insert_head(Node** head, int data); // 头插
    void insert_tail(Node** head, int data); // 尾插
    void delete_node(Node** head, int data); // 删除指定值
    void print_list(Node* head);            // 遍历打印
    链表反转（面试最高频）：
    // 迭代法
    Node* reverse_iter(Node* head) {
        Node *prev = NULL, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // 递归法
    Node* reverse_recursive(Node* head) {
        if (!head || !head->next) return head;
        Node* new_head = reverse_recursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
    }
    验收标准：链表 5 个操作 + 反转，不查资料独立写完，运行通过。这关过了，你的 C 语言就达标了。