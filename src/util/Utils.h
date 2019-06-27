//
// Created by Nan Jiang on 2019-06-27.
//

#ifndef JC_UTILS_H
#define JC_UTILS_H

#include <string>

using namespace std;

class Utils {
public:
    template<typename T>
    static std::string vectorToString(const std::vector<T> &v);
};

#endif //JC_UTILS_H
