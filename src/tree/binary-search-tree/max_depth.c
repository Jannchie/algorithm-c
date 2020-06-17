#include "tree.h"
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

int main(int argc, char const *argv[])
{
    struct TreeNode *root = create_binary_search_tree(10);
    printf("Max Depth: %d\n", max_depth(root));
    return 0;
}