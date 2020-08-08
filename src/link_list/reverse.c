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
    struct ListNode *a = NULL, *b = head, *c;
    while (b != NULL)
    {
        c = b->next;
        b->next = a;
        a = b;
        b = c;
    }
    return a;
}

struct ListNode *double_head_reverse(struct ListNode *head1, struct ListNode *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    struct ListNode *new_head1 = head1->next;
    head1->next = head2;
    struct ListNode *new_head2 = head1;
    return double_head_reverse(new_head1, new_head2);
}

int main(int argc, char const *argv[])
{
    struct ListNode *head = gen_list(10);
    printf("Double head reverse: \n");
    print_list(head);
    head = double_head_reverse(head, NULL);
    print_list(head);
    printf("Iteratively reverseList_: \n");
    print_list(head);
    head = reverseList_iteratively(head);
    print_list(head);
    printf("Recursively reverseList_: \n");
    print_list(head);
    head = reverseList_recursively(head);
    print_list(head);
    return 0;
}
