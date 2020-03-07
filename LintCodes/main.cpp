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
	vector<int> preorder{ 1, 2, 4, 5, 3, 6, 7 }, inorder{ 4, 2, 5, 1, 6, 3, 7 };
	auto root = buildTree(preorder, inorder);

	return 0;
}
