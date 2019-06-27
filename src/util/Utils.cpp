//
// Created by Nan Jiang on 2019-06-27.
//

#include "Utils.h"

using namespace std;

template <typename T>
std::string Utils::vectorToString(const std::vector<T> &v) {
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