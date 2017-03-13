#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <vector>

using namespace std;

vector<int> Merge(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> result;
    result.reserve(vec1.size()+vec2.size());
    auto iter1 = vec1.cbegin(), iter2 = vec2.cbegin();
    while(iter1 != vec1.cend() && iter2 != vec2.cend()) {
        if (*iter1 < *iter2) {
            result.push_back(*iter1);
            ++iter1;
        } else {
            result.push_back(*iter2);
            ++iter2;
        }
    }
    if (iter1 != vec1.cend()) {
        result.insert(result.end(), iter1, vec1.cend());
    } else {
        result.insert(result.end(), iter2, vec2.cend());
    }
    return result;
}

vector<int> MergeSort(const vector<int>& vec) {
    if (vec.size() < 2) return vec;
    int middle = vec.size() >> 1;
    vector<int> vec1(vec.cbegin(), vec.cbegin()+middle);
    vector<int> vec2(vec.cbegin()+middle, vec.cend());
    return Merge(MergeSort(vec1), MergeSort(vec2));
}

#endif
