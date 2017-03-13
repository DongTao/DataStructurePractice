#ifndef _PARTITION_H_
#define _PARTITION_H_

#include <vector>

using namespace std;

int Partition(vector<int>& vec, int begin, int end, int pivot) {
    if (end >= vec.size() || pivot >= vec.size()) return -1;
    swap(vec[end], vec[pivot]);
    int left = begin, right = end-1;
    while (true) {
        while (left < end && vec[left] <= vec[end]) ++left;
        while (right > begin && vec[right] > vec[end]) --right;
        if (left < right) {
            swap(vec[left], vec[right]);
        } else {
            break;
        }
    }
    swap(vec[left], vec[end]);
    return left;
}

#endif
