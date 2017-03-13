#include "quickselect.h"
#include "gtest/gtest.h"

using namespace std;

TEST(QuickSelectSortTest, Empty) {
    vector<int> vec;
    QuickSelectSort(vec, 0);
    EXPECT_TRUE(vec.empty());
    vector<int> vec1;
    QuickSelectSort(vec1, 1);
    EXPECT_TRUE(vec1.empty());
}

TEST(QuickSelectSortTest, SigleValue) {
    vector<int> answer = {2};
    vector<int> vec = {2};
    QuickSelectSort(vec, 0);
    EXPECT_TRUE(equal(vec.begin(), vec.end(), answer.begin()));
}

TEST(QuickSelectSortTest, Normal) {
    vector<int> answer = {1,2,3,5,6,6,12,18,23,33,44,55,72,121,451};
    vector<int> vec = {12,18,44,33,121,2,5,1,72,3,6,6,23,451,55};
    QuickSelectSort(vec, 10);
    for (int i = 0; i <= 10; ++i)
        EXPECT_TRUE(answer[i] == vec[i]);

    EXPECT_TRUE(equal(vec.begin(), vec.begin()+10, answer.begin()));
}

TEST(QuickSelectSortTest, Sorted) {
    vector<int> answer = {1,2,3,5,6,6,12,18,23,33,44,55,72,121,451};
    vector<int> vec = {1,2,3,5,6,6,12,18,23,33,44,55,72,121,451};
    QuickSelectSort(vec, 10);
    for (int i = 0; i <= 10; ++i)
        EXPECT_TRUE(answer[i] == vec[i]);

    EXPECT_TRUE(equal(vec.begin(), vec.begin()+10, answer.begin()));
}

TEST(QuickSelectSortTest, Reversed) {
    vector<int> answer = {1,2,3,5,6,6,12,18,23,33,44,55,72,121,451};
    vector<int> vec(answer.rbegin(), answer.rend());
    PrintVec(vec);

    QuickSelectSort(vec, 10);
    for (int i = 0; i <= 10; ++i)
        EXPECT_TRUE(answer[i] == vec[i]);

    EXPECT_TRUE(equal(vec.begin(), vec.begin()+10, answer.begin()));
}
