#include <stdlib.h>
#include <stdio.h>
/**
 * 链表数据结构 
 */
typedef struct LinkListNode
{
    int val;
    struct LinkListNode *next;
} LinkListNode;

void testLinklist();

LinkListNode *getRandomLinkList(int n);