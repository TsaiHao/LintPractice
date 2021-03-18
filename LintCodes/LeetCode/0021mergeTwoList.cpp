#include "LeetCode.h"
using namespace std;

ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {
    auto p1 = l1, p2 = l2;
    ListNode *mgList = nullptr;
    ListNode *mgp = nullptr;

    while (l1 != nullptr && l2 != nullptr) {
        int x;
        if (l1->val < l2->val) {
            x = l1->val;
            l1 = l1->next;
        } else {
            x = l2->val;
            l2 = l2->next;
        }
        if (mgList == nullptr) {
            mgList = new ListNode(x);
            mgp = mgList;
        } else {
            mgp->next = new ListNode(x);
            mgp = mgp->next;
        }
    }
    while (l1 != nullptr) {
        int x = l1->val;
        l1 = l1->next;
        if (mgList == nullptr) {
            mgList = new ListNode(x);
            mgp = mgList;
        } else {
            mgp->next = new ListNode(x);
            mgp = mgp->next;
        }
    }
    while (l2 != nullptr) {
        int x = l2->val;
        l2 = l2->next;
        if (mgList == nullptr) {
            mgList = new ListNode(x);
            mgp = mgList;
        } else {
            mgp->next = new ListNode(x);
            mgp = mgp->next;
        }
    }
    return mgList;
}