#include <queue>

#include "LeetCode.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	queue<ListNode*> NodeQueue;
	auto travelNode = head;
	while (travelNode != NULL) {
		NodeQueue.push(travelNode);
		if (NodeQueue.size() > n + 1) {
			NodeQueue.pop();
		}
		travelNode = travelNode->next;
	}
	if (NodeQueue.size() == n) {
		head = head->next;
	}
	else {
		auto prevNode = NodeQueue.front();
		NodeQueue.pop();
		auto removeNode = NodeQueue.front();
		NodeQueue.pop();
		prevNode->next = removeNode->next;
	}
	return head;
}