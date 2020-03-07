#include <vector>
#include <algorithm>
#include "LeetCode.h"
using namespace std;

using viter = vector<int>::iterator;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, viter preBeg, viter preEnd, viter inBeg, viter inEnd)
{
	if (preBeg > preEnd || inBeg > inEnd) {
		return nullptr;
	}
	TreeNode* root = new TreeNode(*preBeg);
	if (preBeg == preEnd || preBeg == preEnd - 1) {
		return root;
	}
	// run find every time seems to be too wasty, use map to replace;
	auto inPos = find(inBeg, inEnd, *preBeg);
	int leftLength = inPos - inBeg, rightLength = inEnd - inPos - 1;
	root->left = buildTree(preorder, inorder, preBeg + 1, preBeg + leftLength + 1, inBeg, inBeg + leftLength);
	root->right = buildTree(preorder, inorder, preEnd - rightLength, preEnd, inEnd - rightLength, inEnd);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.empty()) {
		return nullptr;
	}
	return buildTree(preorder, inorder, preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}