//
// Created by Nan Jiang on 2019-06-26.
//

#ifndef JC_SOLUTION_H
#define JC_SOLUTION_H

using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        nums1.insert(nums1.end(),
                     std::make_move_iterator(nums2.begin()),
                     std::make_move_iterator(nums2.end()));

        sort(nums1.begin(), nums1.end());

        size_t size = nums1.size();
        size_t midIndex = size / 2;

        if (size == 0) return -1;

        return ((size % 2) == 0) ? (nums1[midIndex - 1] + nums1[midIndex]) / 2.0 : nums1[midIndex];
    }

    static vector<int> mergeSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        nums1.insert(nums1.end(),
                     std::make_move_iterator(nums2.begin()),
                     std::make_move_iterator(nums2.end()));

        sort(nums1.begin(), nums1.end());

        return nums1;
    }
};

#endif //JC_SOLUTION_H
