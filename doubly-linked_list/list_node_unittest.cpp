#include "list_node.h"
#include "partition.h"
#include "quicksort.h"
#include "gtest/gtest.h"

TEST(ListOperation, ListInit) {
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
    EXPECT_TRUE(ListCompare(head1, answer1));
    PrintList(head1);
    PrintList(answer1);

    ListNode* p1 = nullptr;
    ListNode* p2 = nullptr;

    ListNode* head2 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer2 = ListInit({10,83,323,16,753,23,3,-8});
    p1 = GetNode(head2, 2);
    p2 = GetNode(head2, 5);
    ListNodeSwap(p1, p2);
    EXPECT_TRUE(ListCompare(head2, answer2));

    ListNode* head3 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer3 = ListInit({83,10,23,16,753,323,3,-8});
    p1 = GetNode(head3, 0);
    p2 = GetNode(head3, 1);
    ListNodeSwap(head3, p2);
    EXPECT_TRUE(ListCompare(head3, answer3));
    PrintList(head3);
    PrintList(answer3);

    ListNode* head4 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer4 = ListInit({10,83,323,16,753,23,3,-8});
    p1 = GetNode(head4, 5);
    p2 = GetNode(head4, 2);
    ListNodeSwap(p1, p2);
    EXPECT_TRUE(ListCompare(head4, answer4));

    ListNode* head5 = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer5 = ListInit({10,83,23,16,323,753,3,-8});
    p1 = GetNode(head5, 4);
    p2 = GetNode(head5, 5);
    ListNodeSwap(p1, p2);
    EXPECT_TRUE(ListCompare(head5, answer5));
}

TEST(Partition, Empty) {
    ListNode* list = nullptr;
    ListNode* p1 = GetNode(list, 0);
    ListNode* p2 = GetLastNode(list);
    EXPECT_TRUE(Partition(p1, p2, p1) == nullptr);
}

TEST(Partition, SingleValue) {
    ListNode* list = ListInit({67});
    ListNode* p1 = GetNode(list, 0);
    ListNode* p2 = GetLastNode(list);
    ListNode* pp = Partition(list, p2, p1);
    EXPECT_TRUE(pp == list) << pp->val;
    PrintList(list);
}

TEST(Partition, Normal) {
    ListNode* list = ListInit({5,7,123,5,2,5,6,23,8,5,23,1,9});
    ListNode* p1 = GetNode(list, 1);
    ListNode* p2 = GetLastNode(list);
    ListNode* pp = Partition(list, p2, p1);
    //结果应该为
    EXPECT_TRUE(pp == GetNode(list, 7));
    int i = 0;
    for (; i < 7; ++i)
        EXPECT_TRUE(GetNode(list, i)->val < 7);

    for (;pp != nullptr; pp = pp->next)
        EXPECT_TRUE(pp->val >= 7);

    PrintList(list);
}

TEST(ListQuickSort, Empty) {
    ListNode* null_head = nullptr;
    QuickSort(null_head, null_head);
    EXPECT_TRUE(null_head == NULL);
}

TEST(ListQuickSort, SingleValue) {
    ListNode* head = ListInit({10});
    ListNode* answer = ListInit({10});
    QuickSort(head, head);
    EXPECT_TRUE(ListCompare(head, answer));
}

TEST(ListQuickSort, Normal) {
    ListNode* head = ListInit({10,83,23,16,753,323,3,-8});
    ListNode* answer = ListInit({-8,3,10,16,23,83,323,753});
    ListNode* p2 = GetLastNode(head);
    QuickSort(head, p2);
    PrintList(head);
    EXPECT_TRUE(ListCompare(head, answer));
}
