#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include "LintCode/LintCode.h"
#include "Leetcode/LeetCode.h"

using namespace std;

int main()
{
	ListNode a(1), b(2), c(3), d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	removeNthFromEnd(&a, 2);
	return 0;
}
