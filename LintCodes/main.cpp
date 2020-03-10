#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>
#include "LintCode/LintCode.h"
#include "Leetcode/LeetCode.h"

using namespace std;

int main()
{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	cout << diameterOfBinaryTree(&n1);
	
	return 0;
}
