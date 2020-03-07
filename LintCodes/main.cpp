#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "LintCode/LintCode.h"
#include "Leetcode/LeetCode.h"

using namespace std;

int main()
{
	vector<int> preorder{ 1, 2 }, inorder{ 1, 2 };
	auto root = buildTree(preorder, inorder);

	return 0;
}
