#include <queue>

#include "LeetCode.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    queue<TreeNode*> nodeQ;
    queue<int> layerQ;
    nodeQ.push(root);
    layerQ.push(1);
    vector<int> singleLayer;
    int curLayer = 1;
    
    while (!nodeQ.empty())
    {
        TreeNode* node = nodeQ.front();
        nodeQ.pop();
        int layer = layerQ.front();
        layerQ.pop();

        if (node == NULL) {
            continue;
        }

        if (layer != curLayer) {
            res.push_back(singleLayer);
            singleLayer.clear();
            curLayer = layer;
        }
        singleLayer.push_back(node->val);
        nodeQ.push(node->left);
        layerQ.push(layer+1);
        nodeQ.push(node->right);
        layerQ.push(layer+1);
    }
    res.push_back(singleLayer);
    return res;
}