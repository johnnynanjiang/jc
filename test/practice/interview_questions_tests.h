//
// Created by Nan Jiang on 2019-06-23.
//

#include <string>

using namespace std;

template<typename T>
void mapToString(const std::map<T, T> &m) {
    if (!m.empty()) {
        for (auto &it: m) {
            cout << it.first << "," << it.second << endl;
        }
    }
    cout << endl;
}

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