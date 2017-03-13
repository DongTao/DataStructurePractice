#include "list_node.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "gtest/gtest.h"

TEST(ListInsertionSort, Empty) {
    ListNode* null_head = NULL;
    EXPECT_TRUE(InsertionSort(null_head) == NULL);
}

TEST(ListInsertionSort, SingleValue) {
    ListNode* head = ListInit({10});
    ListNode* answer = ListInit({10});
    EXPECT_TRUE(ListCompare(InsertionSort(head), answer));
}

TEST(ListInsertionSort, Normal) {
    ListNode* head = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer = ListInit({-8,3,10,16,23,83,323,753});
    ListNode* new_head = InsertionSort(head);
    PrintList(new_head);
    EXPECT_TRUE(ListCompare(new_head, answer));
}

TEST(ListMergeSort, Empty) {
    ListNode* null_head = NULL;
    EXPECT_TRUE(MergeSort(null_head) == NULL);
}

TEST(ListMergeSort, SingleValue) {
    ListNode* head = ListInit({10});
    ListNode* answer = ListInit({10});
    EXPECT_TRUE(ListCompare(MergeSort(head), answer));
}

TEST(ListMergeSort, Normal) {
    ListNode* head = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer = ListInit({-8,3,10,16,23,83,323,753});
    ListNode* new_head = MergeSort(head);
    PrintList(new_head);
    EXPECT_TRUE(ListCompare(new_head, answer));
}
