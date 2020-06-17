#include "tree.h"
int rangeSumBST(struct TreeNode *root, int L, int R)
{
    if (root == 0)
    {
        return 0;
    }
    if (root->val <= R && root->val >= L)
    {
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
    else if (root->val < L)
    {
        return rangeSumBST(root->right, L, R);
    }
    else
    {
        return rangeSumBST(root->left, L, R);
    }
}

int main(int argc, char const *argv[])
{
    struct TreeNode *root = create_binary_search_tree(10);
    return 0;
}
