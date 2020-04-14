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

int fun445test(int n1, int n2)
{
    ListNode* l1 = NULL, *l2 = NULL;
    if (n1 == 0) {
        l1 = new ListNode(0);
    }
    else {
        while (n1 != 0) {
            int a = n1 % 10;
            n1 /= 10;
            ListNode* temp = new ListNode(a);
            temp->next = l1;
            l1 = temp;
        }
    }

    if (n2 == 0) {
        l2 = new ListNode(0);
    }
    else {
        while (n2 != 0) {
            int a = n2 % 10;
            n2 /= 10;
            ListNode* temp = new ListNode(a);
            temp->next = l2;
            l2 = temp;
        }
    }

    ListNode* sum = addTwoNumbers(l1, l2);
    while (sum != NULL) {
        cout << sum->val << '\t';
        sum = sum->next;
    }
}