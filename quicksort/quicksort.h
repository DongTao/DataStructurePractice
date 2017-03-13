#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <vector>
#include "../partition/partition.h"
#include "../utils.h"
using namespace std;

void QuickSort(vector<int>& nums, int start, int end) {
    if (nums.empty() || start >= end) return;

    int middle = Partition(nums, start, end, start);
    QuickSort(nums, start, middle-1);
    QuickSort(nums, middle+1, end);
    cout << "sort(" << start << " - " << end << ") ";
    PrintVec(nums);
}

#endif
