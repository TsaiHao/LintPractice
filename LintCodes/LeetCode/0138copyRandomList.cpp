#include <vector>
#include <algorithm>
#include <unordered_map>

#include "LeetCode.h"
using namespace std;

typedef Node138* Nodeptr;
Nodeptr copyRandomList(Nodeptr head) 
{
    if (head == NULL) {
        return NULL;
    }
    unordered_map<Nodeptr, int> oldMap;
    unordered_map<int, Nodeptr> newMap;

    Nodeptr nHead = new Node138(head->val);
    oldMap[head] = 0;
    newMap[0] = nHead;
    Nodeptr next = head->next;
    Nodeptr newNext = nHead;
    int index = 1;
    while(next != NULL)
    {
        oldMap[next] = index;
        
        Nodeptr temp = new Node138(next->val);
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