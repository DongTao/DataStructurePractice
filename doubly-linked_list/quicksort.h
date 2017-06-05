#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include "list_node.h"
#include "partition.h"
#include <iostream>

using namespace std;

void QuickSort(ListNode* begin, ListNode* end) {
    if (begin == nullptr || end == nullptr || begin == end) return;

    PrintList(begin);
    ListNode* pivot = Partition(begin, end, begin);
    if (pivot != nullptr) {
        cout << "pivot: " << pivot->val << endl;
        if (pivot != begin) {
            QuickSort(begin, pivot->prior);
        }
        if (pivot != end) {
            QuickSort(pivot->next, end);
        }
    }
}

#endif
