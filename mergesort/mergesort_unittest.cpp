#include "mergesort.h"
#include <vector>
#include "gtest/gtest.h"
#include "../utils.h"

using namespace std;

TEST(MergeSortTest, Empty) {
    vector<int> vec;
    EXPECT_TRUE(MergeSort(vec).empty());
}

TEST(MergeSortTest, SigleValue) {
    vector<int> answer = {2};
    vector<int> vec = MergeSort({2});
    EXPECT_TRUE(equal(vec.begin(), vec.end(), answer.begin()));
}

TEST(MergeSortTest, Normal) {
    vector<int> answer = {1,2,3,5,6,6,12,18,23,33,44,55,72,121,451};
    vector<int> sorted = MergeSort({12,18,44,33,121,2,5,1,72,3,6,6,23,451,55});
    EXPECT_TRUE(equal(sorted.begin(), sorted.end(), answer.begin()));
}

TEST(MergeSortTest, Sorted) {
    vector<int> answer = {1,2,3,5,6,6,12,18,23,33,44,55,72,121,451};
    vector<int> sorted = MergeSort(answer);
    EXPECT_TRUE(equal(sorted.begin(), sorted.end(), answer.begin()));
}

TEST(MergeSortTest, Reversed) {
    vector<int> answer = {1,2,3,5,6,6,12,18,23,33,44,55,72,121,451};
    vector<int> reversed(answer.rbegin(), answer.rend());
    PrintVec(reversed);
    vector<int> sorted = MergeSort(reversed);
    EXPECT_TRUE(equal(sorted.begin(), sorted.end(), answer.begin()));
}
