//
// Created by Nan Jiang on 2019-06-26.
//

#include "gtest/gtest.h"
#include "leetcode/median_of_two_sorted_arrays/solution.h"

// https://leetcode.com/problems/median-of-two-sorted-arrays/

using namespace std;

TEST(leetcode, merge_two_sorted_arrays) {
    vector<int> a{0, 2}, b{0, 1, 2, 3}, expectedResult{0, 1, 2, 3};
    ASSERT_EQ(expectedResult, Solution::mergeSortedArrays(a, b));
}

TEST(leetcode, median_of_two_sorted_arrays) {
    vector<int> a, b;

    a = {0}, b = {0, 1, 2};
    ASSERT_EQ(1.0, Solution::findMedianSortedArrays(a, b));

    a = {0, 1}, b = {0, 1, 2};
    ASSERT_EQ(1.0, Solution::findMedianSortedArrays(a, b));

    a = {0, 1, 2}, b = {0, 1, 2, 3};
    ASSERT_EQ(1.5, Solution::findMedianSortedArrays(a, b));

    a = {0, 1, 2, 3}, b = {0, 1, 2, 3, 4};
    ASSERT_EQ(2.0, Solution::findMedianSortedArrays(a, b));
}