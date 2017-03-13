#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

#include <vector>

using namespace std;

bool BinarySearch(vector<int>& vec, int num) {
    if (vec.empty()) return false;
    int begin = 0, end = vec.size()-1;
    int middle = 0;
    while (begin <= end) {
        middle = begin + ((end-begin) >> 1);
        if (vec[middle] > num) {
            end = middle-1;
        } else if (vec[middle] < num) {
            begin = middle+1;
        } else {
            return true;
        }
    }
    return false;
}


#endif
