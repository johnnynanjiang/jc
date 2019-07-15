//
// Created by Nan Jiang on 2019-07-15.
//

#include "gtest/gtest.h"

#include <string>

using namespace std;

/* https://leetcode.com/problems/binary-search/
 * https://leetcode.com/submissions/detail/243482387/
 * Runtime: 52 ms, faster than 77.36% of C++ online submissions for Binary Search.
 * Memory Usage: 11 MB, less than 23.94% of C++ online submissions for Binary Search.
 */

int binary_search(const vector<int>& nums, const int target, const int fromIndex, const int toIndex) {
    if (toIndex < fromIndex) return -1;

    int middleIndex = fromIndex + (toIndex - fromIndex) / 2;
    int middleValue = nums.at(middleIndex);

    if(middleValue == target) return middleIndex;
    if(middleValue > target) return binary_search(nums, target, fromIndex, middleIndex - 1);
    if(middleValue < target) return binary_search(nums, target, middleIndex + 1, toIndex);

    return -1;
}

int search(vector<int>& nums, int target) {
    return binary_search(nums, target, 0, nums.size() - 1);
}

TEST(search, binary_search) {
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6};
    vector<int> v2 = {0};
    vector<int> v3 = {2, 5};
    vector<int> v4 = {-1, 0, 3, 5, 9, 12};

    ASSERT_EQ(3, search(v1, 3));
    ASSERT_EQ(-1, search(v2, 3));
    ASSERT_EQ(-1, search(v3, 0));
    ASSERT_EQ(4, search(v4, 9));
}