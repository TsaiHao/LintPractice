
#include "LeetCode.h"
using namespace std;

inline int max(int a, int b)
{
	return a > b ? a : b;
}
int getTreeDeepth(TreeNode* root, int deepth)
{
	if (root->left == NULL && root->right == NULL) {
		return deepth;
	}
	int left = 0, right = 0;
	if (root->left != NULL) {
		left = getTreeDeepth(root->left, deepth + 1);
	}
	if (root->right != NULL) {
		right = getTreeDeepth(root->right, deepth + 1);
	}
	return max(left, right);
}
int diameterOfBinaryTree(TreeNode* root)
{
	if (root == NULL) {
		return 0;
	}
	int leftDeepth = 0, rightDeepth = 0;
	int leftMax = 0, rightMax = 0;
	if (root->left != NULL) {
		++leftDeepth;
		leftDeepth = getTreeDeepth(root->left, leftDeepth);
		leftMax = diameterOfBinaryTree(root->left);
	}
	if (root->right != NULL) {
		++rightDeepth;
		rightDeepth = getTreeDeepth(root->right, rightDeepth);
		rightMax = diameterOfBinaryTree(root->right);
	}
	return max(max(leftDeepth + rightDeepth, rightMax), leftMax);
}