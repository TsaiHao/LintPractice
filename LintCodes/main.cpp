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
	Node node1(1), node2(2), node3(3), node4(4);
	node1.neighbors = { &node2, &node4 };
	node2.neighbors = { &node1, &node3 };
	node3.neighbors = { &node2, &node4 };
	node4.neighbors = { &node1, &node3 };
	auto ret = cloneGraph(&node1);

	return 0;
}
