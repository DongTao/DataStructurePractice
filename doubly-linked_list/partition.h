#ifndef _PARTITION_H_
#define _PARTITION_H_

#include "list_node.h"

ListNode* Partition(ListNode* begin, ListNode* end, ListNode* pivot) {
    if (begin == end) return nullptr;
    ListNode* left = begin;
    ListNode* right = end->prior;
    ListNodeSwap(pivot, end);
    while (true) {
        while (left != end && left->val < end->val) {
            if (left != right) {
                left = left->next;
            } else {
                break;
            }
        }
        while (right != begin && right->val > end->val) {
            if (right != left) {
                right = right->prior;
            } else {
                break;
            }
        }
        if (left != right) {
            ListNodeSwap(left, right);
            swap(left, right);
        } else {
            break;
        }
    }
    ListNodeSwap(left, end);
    swap(left, end);
    return left;
}

#endif
