//
// Created by Nan Jiang on 2019-06-12.
//

#ifndef JC_TWO_SUM_H
#define JC_TWO_SUM_H

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int v = 0, ListNode * n = nullptr) : val(v), next(n) {}
};

ListNode * two_sum(ListNode * l1, ListNode * l2);

#endif //JC_TWO_SUM_H
