#include "list_node.h"
#include "gtest/gtest.h"

TEST(ListOperation, ListInit) {
    //ListNode head(10);
    //ListNode new_head(9);
    //ListNode* ptr_node = NodeInsertPrior(&head, &new_head);
    //PrintList(ptr_node);

    ListNode* head = ListInit({10,83,23,16,753,323,3,-8});
    PrintList(head);
    ListNode* answer = ListInit({-8,3,10,16,23,83,323,753});
    PrintList(answer);
}

TEST(ListOperation, GetNode) {
    ListNode* head = ListInit({10,83,23,16,753,323,3,-8});

    ListNode* ptr = GetNode(head, 0);
    EXPECT_TRUE(ptr != nullptr && ptr->val == 10);
    ptr = GetNode(head, 3);
    EXPECT_TRUE(ptr != nullptr && ptr->val == 16);
    ptr = GetNode(head, 7);
    EXPECT_TRUE(ptr != nullptr && ptr->val == -8);
    ptr = GetNode(head, 8);
    EXPECT_TRUE(ptr == nullptr);
    ptr = GetNode(head, 100);
    EXPECT_TRUE(ptr == nullptr);
}

TEST(ListOperation, NodeInsert) {
    ListNode* head = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer = ListInit({10,83,23,16,123,753,323,3,-8});

    ListNode node(123);
    NodeInsertPrior(GetNode(head, 4), &node);
    EXPECT_TRUE(ListCompare(head, answer));
    PrintList(head);

    ListNode node1(999);
    NodeInsertNext(GetNode(head, 4), &node1);
    ListNode* answer1 = ListInit({10,83,23,16,123,999,753,323,3,-8});
    EXPECT_TRUE(ListCompare(head, answer1));
    PrintList(head);
}

TEST(ListOperation, NodeSwap) {
    ListNode* head1 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer1 = ListInit({-8,83,23,16,753,323,3,10});

    ListNode* new_head1 = GetNode(head1, 7);
    ListNodeSwap(head1, new_head1);
    EXPECT_TRUE(ListCompare(new_head1, answer1));
    PrintList(new_head1);
    PrintList(answer1);

    ListNode* head2 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer2 = ListInit({10,83,323,16,753,23,3,-8});
    ListNodeSwap(GetNode(head2, 2), GetNode(head2, 5));
    EXPECT_TRUE(ListCompare(head2, answer2));

    ListNode* head3 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer3 = ListInit({23,83,10,16,753,323,3,-8});
    ListNode* new_head3 = GetNode(head3, 2);
    ListNodeSwap(head3, new_head3);
    EXPECT_TRUE(ListCompare(new_head3, answer3));
    PrintList(new_head3);
    PrintList(answer3);

    ListNode* head4 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer4 = ListInit({10,83,323,16,753,23,3,-8});
    ListNodeSwap(GetNode(head4, 5), GetNode(head4, 2));
    EXPECT_TRUE(ListCompare(head4, answer4));

    ListNode* head5 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer5 = ListInit({10,83,23,16,323,753,3,-8});
    ListNodeSwap(GetNode(head5, 4), GetNode(head5, 5));
    EXPECT_TRUE(ListCompare(head5, answer5));
}

TEST(Partition, Empty) {
    ListNode* list = nullptr
    EXPECT_TRUE(Partition(vec, 0, vec.size()-1, 0) == -1);
}

//Mark
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

//TEST(ListInsertionSort, Empty) {
//    ListNode* null_head = NULL;
//    EXPECT_TRUE(InsertionSort(null_head) == NULL);
//}
//
//TEST(ListInsertionSort, SingleValue) {
//    ListNode* head = ListInit({10});
//    ListNode* answer = ListInit({10});
//    EXPECT_TRUE(ListCompare(InsertionSort(head), answer));
//}
//
//TEST(ListInsertionSort, Normal) {
//    ListNode* head = ListInit({10,83,23,16,753,323,3,-8});
//    ListNode* answer = ListInit({-8,3,10,16,23,83,323,753});
//    ListNode* new_head = InsertionSort(head);
//    PrintList(new_head);
//    EXPECT_TRUE(ListCompare(new_head, answer));
//}
//
//TEST(ListMergeSort, Empty) {
//    ListNode* null_head = NULL;
//    EXPECT_TRUE(MergeSort(null_head) == NULL);
//}
//
//TEST(ListMergeSort, SingleValue) {
//    ListNode* head = ListInit({10});
//    ListNode* answer = ListInit({10});
//    EXPECT_TRUE(ListCompare(MergeSort(head), answer));
//}
//
//TEST(ListMergeSort, Normal) {
//    ListNode* head = ListInit({10,83,23,16,753,323,3,-8});
//    ListNode* answer = ListInit({-8,3,10,16,23,83,323,753});
//    ListNode* new_head = MergeSort(head);
//    PrintList(new_head);
//    EXPECT_TRUE(ListCompare(new_head, answer));
//}
