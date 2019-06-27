//
// Created by Nan Jiang on 2019-06-26.
//

#ifndef JC_SOLUTION_H
#define JC_SOLUTION_H

using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return -1.0;
    }

    static vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2, vector<int>& result) {
        set_union(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), result.begin());
        return result;
    }
};

#endif //JC_SOLUTION_H
