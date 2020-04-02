#include <vector>
#include <algorithm>
#include <unordered_map>

#include "LeetCode.h"
using namespace std;

typedef Node138 Node;
Node* copyRandomList(Node* head) 
{
    if (head == NULL) {
        return NULL;
    }
    unordered_map<Node*, int> oldMap;
    unordered_map<int, Node*> newMap;

    Node* nHead = new Node(head->val);
    oldMap[head] = 0;
    newMap[0] = nHead;
    Node* next = head->next;
    Node* newNext = nHead;
    int index = 1;
    while(next != NULL)
    {
        oldMap[next] = index;
        
        Node* temp = new Node(next->val);
        newNext->next = temp;
        newNext = newNext->next;
        next = next->next;
        newMap[index] = temp;
        index++;
    }

    next = head;
    newNext = nHead;
    index = 0;
    while(next != NULL)
    {
        if (next->random == NULL) {
            newNext->random = NULL;
        }
        else {
            newNext->random = newMap[oldMap[next->random]];
        }
        
        next = next->next;
        newNext = newNext->next;
    }
    return head;
}