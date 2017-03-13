#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include "list_node.h"

ListNode* InsertionSort(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode dummy;
    dummy.next = head;
    ListNode* p = head;
    while (p && p->next) {
        if (p->next->val < p->val) {
            ListNode* ptr = p->next;
            p->next = p->next->next;
            ListNode* p1 = &dummy;
            for (; p1->next->val <= ptr->val; p1 = p1->next);
            ptr->next = p1->next;
            p1->next = ptr;
        } else {
            p = p->next;
        }
    }
    return dummy.next;
}

#endif
