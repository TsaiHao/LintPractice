#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include "LeetCode.h"
using namespace std;

Node* cloneGraph(Node* node)
{
	if (node == nullptr) {
		return nullptr;
	}
	deque<Node*> toAdd{ node };
	unordered_map<int, Node*> visited;
	Node* ret;
	int times = 0;

	while (!toAdd.empty()) {
		Node* frontNode = toAdd.front();
		toAdd.pop_front();
		if (visited.find(frontNode->val) != visited.end()) {
			continue;
		}
		Node* newNode = new Node(frontNode->val);
		if (times == 0) {
			ret = newNode;
			times = 1;
		}
		visited[frontNode->val] = newNode;
		for (Node* nd : frontNode->neighbors) {
			auto pos = visited.find(nd->val);
			if (pos == visited.end()) {
				toAdd.push_back(nd);
			}
			else {
				pos->second->neighbors.push_back(newNode);
				newNode->neighbors.push_back(pos->second);
			}
		}
	}

	return ret;
}