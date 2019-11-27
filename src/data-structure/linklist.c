#include "linklist.h"

LinkListNode *createNewLinklistNode(int val)
{
    LinkListNode *new = (LinkListNode *)malloc(sizeof(LinkListNode));
    new->next = NULL;
    new->val = val;
    return new;
}

LinkListNode *headInsert(LinkListNode *head, int val)
{
    LinkListNode *new = createNewLinklistNode(val);
    new->next = head;
    return new;
}

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
void testLinklist()
{
    LinkListNode *n = createNewLinklistNode(1);
    n->next = createNewLinklistNode(2);
    printf("val: %d, next: %p\n", n->val, n->next);
}