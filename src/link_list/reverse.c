#include "link_list.h"
struct ListNode *reverseList_recursively(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode *t = reverseList_recursively(head->next);
    head->next->next = head;
    head->next = NULL;
    return t;
}
struct ListNode *reverseList_iteratively(struct ListNode *head)
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
int main(int argc, char const *argv[])
{
    struct ListNode *head = NULL;
    head = list_insert_2(head, 2);
    head = list_insert_2(head, 3);
    head = list_insert_2(head, 1);
    print_list(head);
    // struct ListNode *head = gen_list(10);
    return 0;
}
