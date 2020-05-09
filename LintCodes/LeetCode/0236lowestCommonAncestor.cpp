#include "LeetCode.h"

using namespace std;

TreeNode* search(TreeNode* root, int p, int q, int& n)
{
    int left = 0, right = 0;
    TreeNode* leftPtr = NULL, *rightPtr = NULL;
    if (root->left != NULL)
        leftPtr = search(root->left, p, q, left);
    if (root->right != NULL)
        rightPtr = search(root->right, p, q, right);
    n = left + right + int(root->val == p || root->val == q);
    if (leftPtr != NULL)
        return leftPtr;
    if (rightPtr != NULL)
        return rightPtr;
    if (n == 2) {
        return root;
    }
    return NULL;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    int x = 0;
    return search(root, p->val, q->val, x);
}