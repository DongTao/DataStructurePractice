#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "list_node.h"

ListNode* Merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode head;
    ListNode* tail = &head;
    while (true) {
        if (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        } else if (l1) {
            tail->next = l1;
            break;
        } else {
            tail->next = l2;
            break;
        }
    }
    return head.next;
}

ListNode* MergeSort(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* first = head;
    ListNode* second = head;
    while (second->next && second->next->next) {
        first = first->next;
        second = second->next->next;
    }
    second = first->next;
    first->next = NULL;
    return Merge(MergeSort(head), MergeSort(second));
}

#endif
