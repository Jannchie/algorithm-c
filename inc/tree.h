#include <stdlib.h>
#include "util.h"
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *bst_insert(struct TreeNode *root, int val)
{
    struct TreeNode *c = root;
    if (root == NULL)
    {
        return createNode(val);
    }
    if (val < root->val)
    {
        root->left = bst_insert(root->left, val);
    }
    if (val > root->val)
    {
        root->right = bst_insert(root->right, val);
    }
    return root;
}

struct TreeNode *create_binary_search_tree(int n)
{
    int *data = getShuffledArray(n);
    printArray(data, n);
    struct TreeNode *root = createNode(data[0]);
    for (int i = 1; i < n; i++)
    {
        bst_insert(root, data[i]);
    }
    return root;
}
