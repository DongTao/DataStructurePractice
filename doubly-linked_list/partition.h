#ifndef _PARTITION_H_
#define _PARTITION_H_

#include "list_node.h"

ListNode* Partition(ListNode*& begin, ListNode*& end, ListNode* pivot) {
    if (begin == nullptr || end == nullptr || pivot == nullptr) return nullptr;
    //注意ListNodeSwap会修改引用
    if (pivot != begin) {
        ListNodeSwap(pivot, end);
    } else {
        ListNodeSwap(begin, end);
    }
    ListNode* left = begin;
    ListNode* right = end->prior;
    while (true) {
        while (left != end && left != nullptr && left->val <= end->val) {
            if (left != right) {
                left = left->next;
            } else {
                break;
            }
        }
        while (right != begin && right != nullptr && right->val > end->val) {
            if (right != left) {
                right = right->prior;
            } else {
                break;
            }
        }
        if (left != end && left != nullptr
                && right != begin && right != nullptr
                && left != right) {
            ListNodeSwap(left, right);
        } else {
            break;
        }
    }
    ListNodeSwap(left, end);
    return left;
}

#endif
