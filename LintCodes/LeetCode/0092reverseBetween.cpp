#include "LeetCode.h"

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode temp(0);
    temp.next = head;
    int len = right - left;
    if (len == 0) {
        return head;
    }
    ListNode* p = head;
    ListNode* prev = &temp;
    for (int i = 1; i < left; ++i) {
        prev = prev->next;
        p = p->next;
    }

    ListNode* nt = p->next;
    for (int i = 0; i < len; ++i) {
        p->next = nt->next;
        nt->next = prev->next;
        prev->next = nt;
        nt = p->next;
    }
    return temp.next;
}
