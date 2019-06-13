//
// Created by Nan Jiang on 2019-06-12.
//

#include <iostream>

#include "add_two_numbers.h"

using namespace std;

ostream & operator<<(ostream & os, ListNode * node) {
    ListNode * current_node = node;

    while (current_node != nullptr) {
        os << current_node->val << ", ";
        current_node = current_node->next;
    }

    os << endl;

    return os;
}

ListNode * add_two_numbers(ListNode *l1, ListNode *l2) {
    ListNode * node1 = l1;
    ListNode * node2 = l2;

    ListNode * result_head_node = nullptr;
    ListNode * result_current_node = nullptr;

    int left_over = 0;

    while (node1 != nullptr || node2 != nullptr) {
        int value1 = node1 != nullptr ? node1->val : 0;
        int value2 = node2 != nullptr ? node2->val : 0;

        int sum = value1 + value2;
        int mod = sum % 10;

        ListNode * new_node = new ListNode(0);
        new_node->val = mod + left_over;
        new_node->next = nullptr;

        if (result_head_node == nullptr) result_head_node = new_node;

        if (result_current_node == nullptr) {
            result_current_node = new_node;
        } else {
            result_current_node->next = new_node;
            result_current_node = new_node;
        }

        left_over = sum / 10;

        node1 = node1 == nullptr ? nullptr : node1->next;
        node2 = node2 == nullptr ? nullptr : node2->next;
    }

    if (left_over > 0) {
        ListNode * new_node = (ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = left_over;
        new_node->next = nullptr;

        result_current_node->next = new_node;
    }

    cout << l1 << "+" << endl << l2 << "=" << endl << result_head_node << endl;

    return result_head_node;
}