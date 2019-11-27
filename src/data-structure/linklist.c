#include "linklist.h"

LinkListNode *createNewLinklistNode(int val)
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
    LinkListNode *new = createNewLinklistNode(val);
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
    LinkListNode *new = createNewLinklistNode(val);
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
        return createNewLinklistNode(val);

    LinkListNode *temp = head;

    if (temp->next == NULL)
    {
        temp->next = createNewLinklistNode(val);
        return head;
    }
    tailInsertRecursion(temp->next, val);
}

void testLinklist()
{
    LinkListNode *n = createNewLinklistNode(1);
    n->next = createNewLinklistNode(2);
    printf("val: %d, next: %p\n", n->val, n->next);
}