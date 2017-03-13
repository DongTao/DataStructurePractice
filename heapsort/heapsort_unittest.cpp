#include <vector>
#include "heapsort.h"
#include "gtest/gtest.h"

using namespace std;

TEST(HeapSort, Empty) {
    vector<int> vec;
    EXPECT_TRUE(HeapSort(vec).empty());
}

TEST(HeapSort, SingleValue) {
    vector<int> vec = {67};
    vector<int> result = HeapSort(vec);
    EXPECT_TRUE(result.size() == 1 && result[0] == 67);
}

TEST(HeapSort, Normal) {
    vector<int> vec = {5,7,123,5,2,5,6,23,8,5,23,1,9};
    vector<int> answer = {1,2,5,5,5,5,6,7,8,9,23,23,123};
    vector<int> result = HeapSort(vec);
    EXPECT_TRUE(equal(result.begin(), result.end(), answer.begin()));
}
