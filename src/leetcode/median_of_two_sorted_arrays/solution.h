//
// Created by Nan Jiang on 2019-06-26.
//

#ifndef JC_SOLUTION_H
#define JC_SOLUTION_H

using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> merged;

        set_union(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(merged));

        size_t size = merged.size();

        size_t midIndex = size / 2;

        if (size == 0) return -1;

        return ((size % 2) == 0) ? (merged[midIndex - 1] + merged[midIndex]) / 2.0 : merged[midIndex];
    }

    static vector<int> mergeSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        set_union(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(result));
        return result;
    }
};

#endif //JC_SOLUTION_H
