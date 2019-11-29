#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef int ElemType;
/**
 * 链表数据结构 
 */
typedef struct LinkListNode
{
    ElemType val;
    struct LinkListNode *next;
} LinkListNode;

void testLinklist();

LinkListNode *getRandomLinkList(int n);