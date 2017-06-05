#ifndef _PARTITION_H_
#define _PARTITION_H_

#include "list_node.h"

ListNode* Partition(ListNode* begin, ListNode* end, ListNode* pivot) {
    if (begin == nullptr || end == nullptr || pivot == nullptr) {
        return nullptr;
    }
    ListNodeSwap(*pivot, *end);

    ListNode* left = begin;
    ListNode* right = end->prior;
    while (true) {
        while (left != end && left != nullptr && left->val <= end->val && left != right) {
            left = left->next;
        }
        while (right != begin && right != nullptr && right->val > end->val && right != left) {
            right = right->prior;
        }
        if (left != end && right != begin && left != right) {
            ListNodeSwap(*left, *right);
        } else {
            break;
        }
    }
    // 只有链表为单元素时left->next可能指向空
    if (left->next == nullptr) {
        return left;
    }
    if (left->val <= end->val) {
        left = left->next;
    }
    ListNodeSwap(*left, *end);
    return left;
}

#endif
