#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *prior;
    ListNode *next;
    ListNode(int x = -1) : val(x), prior(nullptr), next(nullptr) {}
};

//注意没有析构，维持双向链表结构
ListNode* NodeDelete(ListNode* ptr_node) {
    if (ptr_node != nullptr) {
        if (ptr_node->prior != nullptr) {
            ptr_node->prior->next = ptr_node->next;
        }
        if (ptr_node->next != nullptr) {
            ptr_node->next->prior = ptr_node->prior;
        }
        ptr_node->prior = ptr_node->next = nullptr;
    }
    return ptr_node;
}

ListNode* NodeInsertNext(ListNode* base_node, ListNode* insert_node) {
    NodeDelete(insert_node);  //维持链表结构
    if (insert_node != nullptr && base_node != nullptr) {
        insert_node->next = base_node->next;
        base_node->next = insert_node;

        insert_node->prior = base_node;
        if (insert_node->next != nullptr) {
            insert_node->next->prior = insert_node;
        }
    }
    return insert_node;
}

ListNode* NodeInsertPrior(ListNode* base_node, ListNode* insert_node) {
    NodeDelete(insert_node);  //维持链表结构
    if (insert_node != nullptr && base_node != nullptr) {
        insert_node->prior = base_node->prior;
        base_node->prior = insert_node;

        insert_node->next = base_node;
        if (insert_node->prior != nullptr) {
            insert_node->prior->next = insert_node;
        }
    }
    return insert_node;
}

ListNode* GetNode(ListNode* base, int index) {
    if (base == nullptr) return nullptr;
    ListNode* ptr = base;
    for (int i = 0; ptr != nullptr && i < index; ++i, ptr = ptr->next) {}
    return ptr;
}

ListNode* ListInit(const vector<int>& input) {
    ListNode head(-1);
    ListNode* base = &head;
    for (auto const &i : input) {
        base = NodeInsertNext(base, new ListNode(i));
    }
    base = head.next;
    NodeDelete(&head);  //去除首节点对head的指向
    return base;
}

//没有检查是否双向链表
bool ListCompare(ListNode* first, ListNode* second) {
    for (;first != nullptr && second != nullptr;
            first=first->next, second=second->next) {
        if (first->val != second->val) {
            return false;
        }
    }
    if (first != nullptr || second != nullptr) {
        return false;
    }
    return true;
}

//仅针对双向链表节点的swap
void ListNodeSwap(ListNode* first, ListNode* second) {
    if (first != nullptr && second != nullptr) {
        if (first->prior == second) {
            NodeInsertPrior(second, NodeDelete(first));
        } else if (second->prior == first) {
            NodeInsertPrior(first, NodeDelete(second));
        } else if (first->next != nullptr) {
            ListNode* pos = first->next;
            NodeInsertPrior(second, first);
            NodeInsertPrior(pos, second);
        } else if (first->prior != nullptr) {
            ListNode* pos = first->prior;
            NodeInsertNext(second, first);
            NodeInsertNext(pos, second);
        }
    }
}

void PrintList(ListNode* list) {
    cout << "Forward:  ";
    ListNode* rIter = nullptr;
    for (ListNode* pIter = list; pIter != nullptr; pIter=pIter->next) {
        cout << pIter->val << " -> ";
        rIter = pIter;
    }
    cout << "NULL" << endl;

    cout << "Backward:  ";
    for (; rIter != nullptr; rIter=rIter->prior) {
        cout << rIter->val << " -> ";
    }
    cout << "NULL" << endl;
}

#endif
