//
// Created by Nan Jiang on 2019-06-26.
//

#include "gtest/gtest.h"
#include "leetcode/median_of_two_sorted_arrays/solution.h"

// https://leetcode.com/problems/median-of-two-sorted-arrays/

using namespace std;

TEST(leetcode, merge_two_sorted_arrays) {
    vector<int> a, b, expectedResult;

    a = {1, 1, 3}, b = {1, 4}, expectedResult = {1, 1, 1, 3, 4};
    ASSERT_EQ(expectedResult, Solution::mergeSortedArrays(a, b));

    a = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4}, b = {1, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4},
    expectedResult = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
    ASSERT_EQ(expectedResult, Solution::mergeSortedArrays(a, b));
}

TEST(leetcode, median_of_two_sorted_arrays) {
    vector<int> a, b;

    a = {0}, b = {0, 1, 2};
    ASSERT_EQ(0.5, Solution::findMedianSortedArrays(a, b));

    a = {0, 1}, b = {0, 1, 2};
    ASSERT_EQ(1.0, Solution::findMedianSortedArrays(a, b));

    a = {0, 1, 2}, b = {0, 1, 2, 3};
    ASSERT_EQ(1, Solution::findMedianSortedArrays(a, b));

    a = {}, b = {0};
    ASSERT_EQ(0, Solution::findMedianSortedArrays(a, b));

    a = {1, 1, 3}, b = {1, 4, 4, 4};
    ASSERT_EQ(3.0, Solution::findMedianSortedArrays(a, b));
}