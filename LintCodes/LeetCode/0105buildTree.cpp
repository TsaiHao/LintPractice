#include <algorithm>

#include "LeetCode.h"
using namespace std;

using viter = vector<int>::iterator;
TreeNode* rebuildTree(viter preBeg, viter preEnd, viter inBeg, viter inEnd)
{
    if (preBeg >= preEnd) {
        return NULL;
    }
    TreeNode* root = new TreeNode(*preBeg);

    auto inMid = find(inBeg, inEnd, *preBeg);
    int left = inMid - inBeg, right = inEnd - inMid - 1;
    root->left = rebuildTree(preBeg + 1, preBeg + left + 1, 
            inBeg, inMid);
    root->right = rebuildTree(preBeg + left + 1, preEnd, 
            inMid + 1, inEnd);
    
    return root;
}

//same with 1488
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int)
{
    auto root = rebuildTree(preorder.begin(), preorder.end(), 
            inorder.begin(), inorder.end());
    return root;
}