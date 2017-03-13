#include "binary_search.h"
#include "gtest/gtest.h"

TEST(BinarySearch, Empty) {
    vector<int> vec;
    EXPECT_FALSE(BinarySearch(vec, 0));
    EXPECT_FALSE(BinarySearch(vec, 22));
    EXPECT_FALSE(BinarySearch(vec, -11));
}

TEST(BinarySearch, SingleValue) {
    vector<int> vec = {1};
    EXPECT_TRUE(BinarySearch(vec, 1));

    EXPECT_FALSE(BinarySearch(vec, 0));
    EXPECT_FALSE(BinarySearch(vec, 22));
    EXPECT_FALSE(BinarySearch(vec, -11));
}

TEST(BinarySearch, Normal) {
    vector<int> vec = {1,3,5,7,9,11,13,15,17};
    EXPECT_TRUE(BinarySearch(vec, 1));
    EXPECT_TRUE(BinarySearch(vec, 5));
    EXPECT_TRUE(BinarySearch(vec, 9));
    EXPECT_TRUE(BinarySearch(vec, 17));

    EXPECT_FALSE(BinarySearch(vec, 0));
    EXPECT_FALSE(BinarySearch(vec, -1));
    EXPECT_FALSE(BinarySearch(vec, 6));
    EXPECT_FALSE(BinarySearch(vec, 88));
}
