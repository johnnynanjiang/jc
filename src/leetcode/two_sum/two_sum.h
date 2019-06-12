//
// Created by Nan Jiang on 2019-06-12.
//

#ifndef JC_TWO_SUM_H
#define JC_TWO_SUM_H

struct Node {
    int value;
    Node * next;
    Node(int v, Node * n) : value(v), next(n) {}
};

int two_sum(Node * node1, Node * node2);

#endif //JC_TWO_SUM_H
