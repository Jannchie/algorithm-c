#include "tree.h"
#include <queue>
using namespace std;
void draw_binary_tree(struct TreeNode *root)
{
    queue<struct TreeNode *> q;

    q.push(root);
    while (!q.empty())
    {
        for (int layer_size = q.size(); layer_size; layer_size--)
        {
            struct TreeNode *c_node = q.front();
            printf("%d ", c_node->val);
            q.pop();
            if (c_node->left != NULL)
            {
                q.push(c_node->left);
            }
            if (c_node->right != NULL)
            {
                q.push(c_node->right);
            }
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    struct TreeNode *root = create_binary_search_tree(10);
    draw_binary_tree(root);
    return 0;
}
