#include "LeetCode.h"
using namespace std;

void preTrav(TreeNode* root, vector<int>& data)
{
    if (root == NULL) {
        return;
    }
    data.push_back(root->val);
    preTrav(root->left, data);
    preTrav(root->right, data);
}
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> data;
    preTrav(root, data);
    return data;
}