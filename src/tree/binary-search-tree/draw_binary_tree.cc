#include "tree.h"
#include <queue>
using namespace std;

int max_depth(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left = max_depth(root->left);
        int right = max_depth(root->right);
        return 1 + (left > right ? left : right);
    }
}
int pow(int x, int y)
{
    int result = 1;
    if (x == 0)
        return 0;
    if (x != 0 && y <= 0)
    {
        return 1;
    }
    while (y--)
    {
        result *= x;
    }
    return result;
}

struct LinkListNode
{
    int val;
    struct LinkListNode *next;
};

struct TreePosition
{
    int layer;
    int ordinal;
    struct TreePosition *next;
};

void draw_binary_tree(struct TreeNode *root)
{
    struct TreePosition *p = (TreePosition *)malloc(sizeof(p));
    p = NULL;
    int depth = max_depth(root);
    struct LinkListNode *pos_array[10];
    for (int i = 1; i <= depth + 1; i++)
    {
        struct LinkListNode *head = (LinkListNode *)malloc(sizeof(head));
        head->next = NULL;
        pos_array[i] = head;

        for (int j = 0; j < pow(2, i - 1); j++)
        {
            struct LinkListNode *node = (LinkListNode *)malloc(sizeof(head));
            node->val = 0;
            struct LinkListNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    queue<struct TreeNode *> q;
    printf("Depth: %d\n", depth);
    printf("Max Layer Count: %d\n", pow(2, depth - 1));
    int i = 1;
    q.push(root);
    while (!q.empty())
    {
        int c = 0;
        TreePosition *current_pos = p;
        int off = 0;
        int delta_layer = 0;

        for (int layer_size = q.size(); layer_size > 0; layer_size--)
        {
            struct TreeNode *c_node = q.front();
            q.pop();
            if (!c_node)
            {
                int d = i;
                int count = 1;
                int c = 0;
                struct LinkListNode *tmp = pos_array[d]->next;
                while (tmp->val != 0 && tmp->next != NULL)
                {
                    tmp = tmp->next;
                    c += 1;
                }

                tmp->val = d == i ? -1 : -2;
                for (d = i + 1; d < depth + 2; d++)
                {
                    struct LinkListNode *tmp = pos_array[d]->next;
                    int start = c * pow(2, d - i);
                    int times = pow(2, d - i);
                    while (start--)
                    {
                        tmp = tmp->next;
                    }
                    while (times--)
                    {
                        tmp->val = -2;
                        tmp = tmp->next;
                    }
                }
                struct LinkListNode *temp = pos_array[d];
                continue;
            }
            struct LinkListNode *tmp = pos_array[i]->next;
            while (tmp->val != 0 && tmp->next != NULL)
            {
                tmp = tmp->next;
            };
            tmp->val = c_node->val;
            if (c_node->left != NULL)
            {
                q.push(c_node->left);
            }
            else
            {
                q.push(NULL);
            }
            if (c_node->right != NULL)
            {
                q.push(c_node->right);
            }
            else
            {
                q.push(NULL);
            }
        }
        i++;
    }
    int is_first = 1;
    for (int h = 1; h <= depth + 1; h++)
    {
        int offset = (pow(2, depth - h + 1) - 1);
        int interval = (pow(2, depth - h + 2) - 1);
        int is_first = 1;
        struct LinkListNode *current = pos_array[h]->next;
        while (current)
        {
            is_first ? printf("%*s", offset, "") : printf("%*s", interval, "");
            is_first = 0;
            if (current->val == -1)
            {
                printf("×");
            }
            else if (current->val == -2)
            {
                printf(" ");
            }
            else
            {
                printf("%0X", current->val);
            }
            current = current->next;
        }
        printf("\n");
        for (int i = 0; i < offset / 2; i++)
            printf(" ");

        current = pos_array[h]->next;
        while (current != NULL)
        {
            if (current->val > -1)
            {
                printf("┏");
                for (int i = 0; i < offset / 2; i++)
                    printf("━");
                printf("┻");
                for (int i = 0; i < offset / 2; i++)
                    printf("━");
                printf("┓");
                for (int i = 0; i < offset; i++)
                    printf(" ");
            }
            else
            {
                printf(" ");
                for (int i = 0; i < offset / 2; i++)
                    printf(" ");
                printf(" ");
                for (int i = 0; i < offset / 2; i++)
                    printf(" ");
                printf(" ");
                for (int i = 0; i < offset; i++)
                    printf(" ");
            }
            current = current->next;
        }

        printf("\n");
    }

    return;
}

int main(int argc, char const *argv[])
{
    struct TreeNode *root = create_binary_search_tree(10);
    draw_binary_tree(root);
    return 0;
}
