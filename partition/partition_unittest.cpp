#include "partition.h"
#include <vector>
#include "gtest/gtest.h"

using namespace std;

TEST(Partition, Empty) {
    vector<int> vec;
    EXPECT_TRUE(Partition(vec, 0, vec.size()-1, 0) == -1);
}

TEST(Partition, SingleValue) {
    vector<int> vec = {67};
    EXPECT_TRUE(Partition(vec, 0, vec.size()-1, 0) == 0);
}

TEST(Partition, Normal) {
    vector<int> vec = {5,7,123,5,2,5,6,23,8,5,23,1,9};
    //结果应该为5,5,2,5,6,5,1
    int pivot = Partition(vec, 0, vec.size()-1, 1);
    EXPECT_TRUE(vec[pivot] == 7);
    int i = 0;
    for (; i < pivot; ++i)
        EXPECT_TRUE(vec[i] < 7);

    EXPECT_TRUE(i == 7);

    for (i = pivot; i < vec.size(); ++i)
        EXPECT_TRUE(vec[i] >= 7);
}
