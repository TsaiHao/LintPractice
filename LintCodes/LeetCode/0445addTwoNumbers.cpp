#include "LeetCode.h"
#include <iostream>
using namespace std;

ListNode* reverse_list(ListNode* l1)
{
    if (l1 == NULL) {
        return NULL;
    }
    decltype(l1) step = l1->next, l1copy = l1;
    
    while(step != NULL)
    {
        auto next = step->next;
        step->next = l1;
        l1 = step;
        step = next;
    }
    l1copy->next = NULL;
    return l1;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
    decltype(l1) rl1 = reverse_list(l1), rl2 = reverse_list(l2);
    ListNode* sum = NULL;
    ListNode* temp;
    int overload = 0;
    while (rl1 != NULL && rl2 != NULL)
    {
        int a = rl1->val + rl2->val + overload;
        temp = new ListNode(a % 10);
        overload = a / 10;
        temp->next = sum;
        sum = temp;
        rl1 = rl1->next;
        rl2 = rl2->next;
    }

    while (rl1 != NULL)
    {
        int a = rl1->val + overload;
        temp = new ListNode(a % 10);
        overload = a / 10;
        temp->next = sum;
        sum = temp;
        rl1 = rl1->next;
    }
    while (rl2 != NULL)
    {
        int a = rl2->val + overload;
        temp = new ListNode(a % 10);
        overload = a / 10;
        temp->next = sum;
        sum = temp;
        rl2 = rl2->next;
    }

    if (overload != 0)
    {
        temp = new ListNode(overload);
        temp->next = sum;
        sum = temp;
    }

    return sum;
}

