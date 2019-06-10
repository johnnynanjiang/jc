#include <iostream>
#include <vector>
#include <array>

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

int main (int argc, char *argv[]) {
    std::vector<int> v = {0, 1, 2, 3};
    int arr[] = {4, 5, 6};
    v.push_back(*arr);

    std::cout << "Hello world!" << std::endl;
    std::cout << "vector v: " << vectorToString(v) << std::endl;

    return 0;
}