//
// Created by Nan Jiang on 2019-06-12.
//

#ifndef JC_ADD_TWO_NUMBERS_H
#define JC_ADD_TWO_NUMBERS_H

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int v = 0, ListNode * n = nullptr) : val(v), next(n) {}
};

ListNode * add_two_numbers(ListNode *l1, ListNode *l2);

#endif //JC_ADD_TWO_NUMBERS_H
