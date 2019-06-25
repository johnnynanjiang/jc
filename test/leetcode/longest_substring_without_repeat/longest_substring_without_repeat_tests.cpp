//
// Created by Nan Jiang on 2019-06-25.
//

#include "gtest/gtest.h"
#include "leetcode/longest_substring_without_repeat/longest_substring_without_repeat.h"

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

TEST(leetcode, longest_substring_without_repeat) {
    ASSERT_EQ(0, Solution::lengthOfLongestSubstring("")); // none
    ASSERT_EQ(1, Solution::lengthOfLongestSubstring("a")); // a
    ASSERT_EQ(1, Solution::lengthOfLongestSubstring("aa")); // a
    ASSERT_EQ(2, Solution::lengthOfLongestSubstring("abb")); // ab
    ASSERT_EQ(3, Solution::lengthOfLongestSubstring("abc")); // abc
    ASSERT_EQ(3, Solution::lengthOfLongestSubstring("abcab")); // bca
    ASSERT_EQ(4, Solution::lengthOfLongestSubstring("abcdc")); // abcd
    ASSERT_EQ(7, Solution::lengthOfLongestSubstring("abcdcbaefg")); // dcbaefg
}