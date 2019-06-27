//
// Created by Nan Jiang on 2019-06-27.
//

#include "gtest/gtest.h"

// TODO: only works for vector<int>, need to make it generic
template <typename T>
std::string vectorToString(const std::vector<T> &v) {
    std::string str = "{";

    if (!v.empty()) {
        auto it = v.begin();

        for (; it < v.end() - 1; it++)
        {
            str += std::to_string(*it) + ", ";
        }
        str += std::to_string(*it);
    }

    return str + "}";
}

TEST(Utils, vector_to_string) {
    std::vector<int> v{1, 2, 3, 4, 5};
    ASSERT_EQ("{1, 2, 3, 4, 5}", vectorToString<int>(v));
}