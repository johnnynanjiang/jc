//
// Created by Nan Jiang on 2019-07-29.
//

#include "gtest/gtest.h"

#include <vector>

using namespace std;

std::string to_string(const std::vector<int> &v) {
    std::string output{};

    for (auto e : v) {
        output += to_string(e) + ", ";
    }

    return output;
}

vector<int> &bubble_sort(vector<int> &v) {
    int last = v.size();

    while (last > 1) {
        for (int i = 0; i < last - 1; ++i) {
            if (v[i] > v[i + 1]) {
                std::swap(v[i], v[i + 1]);
            }
        }

        --last;
    }

    return v;
}

TEST(sorting, bubble_sort) {
    vector<int> v1 = {6, 5, 4, 3, 2, 1};

    ASSERT_EQ("1, 2, 3, 4, 5, 6, ", to_string(bubble_sort(v1)));

    vector<int> v2 = {6};

    ASSERT_EQ("6, ", to_string(bubble_sort(v2)));

    vector<int> v3 = {};

    ASSERT_EQ("", to_string(bubble_sort(v3)));
}