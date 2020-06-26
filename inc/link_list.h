#include <util.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
/**
 * 打印链表
 */
void print_list(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct ListNode *create_list_node(int n)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(new_node));
    new_node->val = n;
    new_node->next = NULL;
}

/**
 * 头部插入
 * 循环操作
 * 缺点是需要判断头结点为空
 */
struct ListNode *list_head_insert(struct ListNode *head, int val)
{
    struct ListNode *node = create_list_node(val);
    node->next = head;
    return node;
}

/**
 * 顺序插入链表 - 循环
 * 构造一个虚拟头结点，值为最小值。
 * 这样就可以将头部插入情况转换为中间插入情况，且无需考虑空链表插入。
 */
struct ListNode *list_insert(struct ListNode *head, int val)
{
    struct ListNode *new_node = create_list_node(val);
    struct ListNode *virtual_head = create_list_node(0); // 虚拟头结点
    virtual_head->next = head;                           //指向原头结点
    struct ListNode *temp = virtual_head;
    // 寻找插入点
    while (temp->next != NULL && temp->next->val < val)
    {
        temp = temp->next;
    }
    // 插入
    new_node->next = temp->next;
    temp->next = new_node;
    // 返回临时结点的下一个结点，因为头结点可能会变动
    return virtual_head->next;
}
/**
 * 顺序插入链表 - 循环
 * 需要考虑头插、头不存在、正常插入这三种情况
 */
struct ListNode *list_insert_2(struct ListNode *head, int n)
{
    struct ListNode *new_node = create_list_node(n);
    if (head == NULL)
    {
        return new_node;
    }
    struct ListNode *temp = head;
    if (n < head->val)
    {
        head = list_head_insert(head, n);
        return head;
    }

    while (temp->next != NULL && temp->next->val < n)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

struct ListNode *gen_list(int n)
{
    int *a = getShuffledArray(n);
    struct ListNode *head = create_list_node(0);
    for (int i = 0; i < n; i++)
    {
        head = list_insert(head, a[i]);
    }
    return head->next;
}

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *a = NULL;
    struct ListNode *b = head;
    while (b != NULL)
    {
        struct ListNode *c = b->next;
        b->next = a;
        a = b;
        b = c;
    }
    return a;
}
