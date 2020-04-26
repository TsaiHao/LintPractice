#include <algorithm>
#include <string.h>

#include "LeetCode.h"
using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if (lists.empty()) {
        return NULL;
    }
    size_t N = lists.size();
    bool* flag = new bool[N];
    memset(flag, false, N * sizeof(bool));
    size_t last = N;
    ListNode* head = NULL;
    ListNode* listPtr = head;

    while (last > 0)
    {
        int minIndex = -1;
        int minVal = INT32_MAX;
        for (size_t i = 0; i < N; ++i)
        {
            if (lists[i] == NULL) {
                if (!flag[i]) {
                    flag[i] = true;
                    --last;
                }
                continue;
            }
            if (lists[i]->val < minVal) {
                minIndex = i;
                minVal = lists[i]->val;
            }
        }
        if (minIndex != -1) {
            ListNode* temp = new ListNode(lists[minIndex]->val);
            lists[minIndex] = lists[minIndex]->next;
            if (head == NULL) {
                head = temp;
                listPtr = head;
            }
            else {
                listPtr->next = temp;
                listPtr = listPtr->next;
            }
        }
    }
    return head;
}

void test0023()
{
    ListNode* l1, *l2, *l3;
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(5);

    l3 = new ListNode(6);
    l3->next = new ListNode(10);

    vector<ListNode*> lists {l1, l2, l3};
    ListNode* ret = mergeKLists(lists);
    int i = 0;
    while (ret != NULL)
    {
        cout << i << "  element is  " << ret->val << endl;
        ret = ret->next;
    }
    cout << "test over" << endl;
}