#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = -1) : val(x), next(nullptr) {}
};

ListNode* NodeInsert(ListNode* base_node, ListNode* insert_node) {
    insert_node->next = base_node->next;
    base_node->next = insert_node;
    return insert_node;
}

ListNode* ListInit(const vector<int>& input) {
    ListNode head(-1);
    ListNode* base = &head;
    for (auto const &i : input) {
        ListNode* tmp_node = new ListNode(i);
        base = NodeInsert(base, tmp_node);
    }
    return head.next;
}

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

//将ptr->next移至base->next位置
bool ListNodeMove(ListNode* ptr, ListNode* base) {
    if (ptr != NULL && ptr->next != NULL &&
            base != NULL && base->next != NULL) {
        ListNode* tmp = ptr->next->next;
        ptr->next->next = base->next;
        base->next = ptr->next;
        ptr->next = tmp;
        return true;
    }
    return false;
}

void PrintList(ListNode* list) {
    for (ListNode* pIter = list; pIter != nullptr; pIter=pIter->next) {
        cout << pIter->val << " -> ";
    }
    cout << "NULL" << endl;
}

#endif
