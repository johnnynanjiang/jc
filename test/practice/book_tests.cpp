//
// Created by Nan Jiang on 2019-06-23.
//

#include "gtest/gtest.h"

#include <string>

using namespace std;

// C++ Primer Plus 5th Edition, chapter 7 @ page 329 in book
void showReview(const string & review) {
    cout << review << endl;
}

void (*showReviewPtr)(const string & review);

TEST(cpp_primer_plus_5th, function_pointer) {
    vector<string> reviews = {"a", "b", "c"};
    vector<string>::iterator iterator;

    showReviewPtr = showReview;

    for_each(reviews.begin(), reviews.end(), showReviewPtr);
}

// C++ Primer Plus 5th Edition, chapter 16 @ page 885 in book
TEST(cpp_primer_plus_5th, vector_iteration) {
    vector<string> reviews {"a", "b", "c"};
    for_each(reviews.begin(), reviews.end(), showReview);
}

// https://liam.page/2018/01/18/volatile-in-C-and-Cpp/
TEST(cpp, volatile) {
    volatile int *p = new int(0);
    int a, b;
    a = *p;
    b = *p;

    ASSERT_EQ(0, a);
    ASSERT_EQ(0, b);

    delete p;
}

// C++ Primer Plus 5th Edition, chapter 16 @ page 923 in book
bool sortAlphabetically(string & a, string & b) {
    return a < b;
}

// TODO: to be implemented properly
template<typename T>
string toString(T & v) {
    string str = std::to_string(std::forward<T>(v));
    cout << str << endl;
    return str;
}

TEST(cpp_primer_plus_5th, vector_sort) {
    vector<string> reviews {"d", "a", "c", "b"};

    for(string s : reviews) {
        cout << s << endl;
    }

    sort(reviews.begin(), reviews.end(), sortAlphabetically);

    for(string s : reviews) {
        cout << s << endl;
    }
}