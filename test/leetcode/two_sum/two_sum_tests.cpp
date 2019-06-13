//
// Created by Nan Jiang on 2019-06-12.
//

#include "gtest/gtest.h"
#include "leetcode/two_sum/two_sum.h"

// https://leetcode.com/problems/add-two-numbers/

TEST(leetcode, two_sum) {
    // 3 -> 2 -> 1 = 123
    ListNode node_a_3{1, nullptr};
    ListNode node_a_2{2, &node_a_3};
    ListNode node_a_1{3, &node_a_2};

    // 7 -> 6 -> 5 ->4 = 4567
    ListNode node_b_4{4, nullptr};
    ListNode node_b_3{5, &node_b_4};
    ListNode node_b_2{6, &node_b_3};
    ListNode node_b_1{7, &node_b_2};

    /*
     expected result should be:
     123 + 4567 = 4690
     0 -> 9 -> 6 -> 4
    */
    ListNode *node = two_sum(&node_a_1, &node_b_1);

    ASSERT_EQ(node->val, 0);
    ASSERT_NE(node->next, nullptr);
    node = node->next;
    ASSERT_EQ(node->val, 9);
    ASSERT_NE(node->next, nullptr);
    node = node->next;
    ASSERT_EQ(node->val, 6);
    ASSERT_NE(node->next, nullptr);
    node = node->next;
    ASSERT_EQ(node->val, 4);
    ASSERT_EQ(node->next, nullptr);
}