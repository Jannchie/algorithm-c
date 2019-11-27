#include "linklist.h"

LinkListNode *createLinklistNode(int val)
{
    LinkListNode *new = (LinkListNode *)malloc(sizeof(LinkListNode));
    new->next = NULL;
    new->val = val;
    return new;
}
/**
 * 打印链表
 */
void printLinkList(LinkListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

/**
 * 头部插入
 * 循环操作
 * 缺点是需要判断头结点为空
 */
LinkListNode *headInsert(LinkListNode *head, int val)
{
    LinkListNode *new = createLinklistNode(val);
    new->next = head;
    return new;
}

/**
 * 朴素尾部插入
 * 循环操作
 * 缺点是需要判断头结点为空
 */
LinkListNode *tailInsert(LinkListNode *head, int val)
{
    LinkListNode *new = createLinklistNode(val);
    LinkListNode *temp = head;
    if (head == NULL)
        return new;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
    return head;
}

/**
 * 递归尾部插入
 */
LinkListNode *tailInsertRecursion(LinkListNode *head, int val)
{
    if (head == NULL)
        return createLinklistNode(val);

    LinkListNode *temp = head;

    if (temp->next == NULL)
    {
        temp->next = createLinklistNode(val);
        return head;
    }
    tailInsertRecursion(temp->next, val);
}

/**
 * 创建定长随机链表
 */
LinkListNode *createRandomLinklist(int len)
{
    if (len <= 0)
    {
        return NULL;
    }
    LinkListNode *head = createLinklistNode(rand());
    int i = 1;
    while (i++ < len)
    {
        LinkListNode *temp = createLinklistNode(rand());
        temp->next = head;
        head = temp;
    }
    return head;
}

/**
 * 创建定长顺序链表
 */
LinkListNode *creatSortedLinklist(int len)
{
    int val = rand() % 10;
    if (len <= 0)
    {
        return NULL;
    }
    LinkListNode *head = createLinklistNode(val += rand() % 10);
    int i = 1;
    while (i++ < len)
    {
        head = tailInsert(head, val += rand() % 10);
    }
    return head;
}

void testLinklist()
{
    LinkListNode *l = creatSortedLinklist(5);
    printLinkList(l);
}