#include "link_list.h"

void double_point_insert(struct ListNode **head, int data)
{
    struct ListNode **p = head;
    struct ListNode *new = create_list_node(data);
    while ((*p) != NULL && (*p)->val < data)
    {
        p = &(*p)->next;
    }
    new->next = *p;
    *p = new;
}


int main(int argc, char const *argv[])
{
    struct ListNode *head = NULL;
    double_point_insert(&head, 1);
    double_point_insert(&head, 3);
    double_point_insert(&head, 4);
    double_point_insert(&head, 2);
    print_list(head);
    return 0;
}
