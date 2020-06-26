#include "link_list.h"
struct ListNode *merge_two_lists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode *a = l1;
    struct ListNode *b = l2;
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *c = head;
    while (a != NULL && b != NULL)
    {
        if (a->val < b->val)
        {
            c->next = a;
            a = a->next;
        }
        else
        {
            c->next = b;
            b = b->next;
        }
        c = c->next;
    }
    if (a != NULL)
    {
        c->next = a;
    }
    if (b != NULL)
    {
        c->next = b;
    }
    return head->next;
}
int main(int argc, char const *argv[])
{
    struct ListNode *a = gen_list(10);
    struct ListNode *b = gen_list(5);
    print_list(merge_two_lists(a, b));
    return 0;
}
