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


template<typename ... Args>
std::string formatString(const std::string &format, Args ... args) {
    size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1;
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args ...);
    return std::string(buf.get(), buf.get() + size - 1);
}

TEST(Utils, format_string) {
    ASSERT_EQ("This is `string` and `10`", formatString("This is `%s` and `%d`", "string", 10));
}