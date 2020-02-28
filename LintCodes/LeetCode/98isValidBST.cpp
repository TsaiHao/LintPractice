#include <queue>

#include "LeetCode.h"
using namespace std;

bool isValidBST(TreeNode* root)
{
	if (root == NULL) {
		return true;
	}
	if (!(root->left == NULL) && !(root->right == NULL)) {
		return (root->val > root->left->val) &&
			(root->val < root->right->val) &&
			isValidBST(root->left) &&
			isValidBST(root->right);
	}
	if (!(root->left == NULL)) {
		return (root->val > root->left->val) && isValidBST(root->left);
	}
	if (!(root->right == NULL)) {
		return (root->val < root->right->val) && isValidBST(root->right);
	}
	return true;
}