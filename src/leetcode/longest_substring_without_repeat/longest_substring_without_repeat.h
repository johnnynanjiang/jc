//
// Created by Nan Jiang on 2019-06-25.
//

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        if (s.length() <= 0) return 0;

        int start = 0;
        int longestLength = 1;
        int currentLength = 1;
        int i = start;

        while (++i < s.length()) {
            int matchAtIndex = s.find(s[i], start);

            if (matchAtIndex >= 0 && (matchAtIndex != i)) {
                start = matchAtIndex + 1;
                i = start;
                currentLength = 1;
            } else {
                ++currentLength;
            }

            if (longestLength < currentLength) {
                longestLength = currentLength;
            }
        }

        return longestLength;
    }
};