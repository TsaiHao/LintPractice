#include "LeetCode.h"
#include <algorithm>
#include <sstream>
using namespace std;

// only work for tree without duplicate value!
class Codec {
public:
    using vit = vector<int>::iterator;
    TreeNode* buildTree(vit preBeg, vit preEnd, vit midBeg, vit midEnd)
    {
        if (preBeg >= preEnd)
        {
            return NULL;
        }
        int val = *preBeg;
        TreeNode* root = new TreeNode(val);
        vit midSplit = find(midBeg, midEnd, val);
        vit preSplit = preBeg + (midSplit - midBeg) + 1;
        root->left = buildTree(preBeg + 1, preSplit, midBeg, midSplit);
        root->right = buildTree(preSplit, preEnd, midSplit + 1, midEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& midOrder)
    {
        if (preOrder.empty())
        {
            return NULL;
        }
        return buildTree(preOrder.begin(), preOrder.end(),
            midOrder.begin(), midOrder.end());
    }

    void preSerial(TreeNode* root, stringstream& ss)
    {
        if (root == NULL)
        {
            return;
        }
        ss << root->val << ",";
        preSerial(root->left, ss);
        preSerial(root->right, ss);
    }
    void midSerial(TreeNode* root, stringstream& ss)
    {
        if (root==NULL)
        {
            return;
        }
        midSerial(root->left, ss);
        ss << root->val << ",";
        midSerial(root->right, ss);
    }
    vector<int> deserialString(string&& s)
    {
        stringstream ss(s);
        vector<int> v;
        char comma;
        int x;
        while (ss >> x)
        {
            v.push_back(x);
            ss >> comma;
        }
        return v;
    }

    string serialize(TreeNode* root) {
        stringstream ss;
        preSerial(root, ss);
        midSerial(root, ss);
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        size_t mid = data.size() / 2;
        auto preorder = deserialString(data.substr(0, mid));
        auto midorder = deserialString(data.substr(mid, mid));
        return buildTree(preorder, midorder);
    }
};