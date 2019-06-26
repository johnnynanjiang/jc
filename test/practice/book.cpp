//
// Created by Nan Jiang on 2019-06-23.
//

#include "gtest/gtest.h"

#include <string>

using namespace std;

void showReview(const string & review) {
    cout << review << endl;
}

void (*showReviewPtr)(const string & review);

// chapter 7 @ page 329 in book
TEST(cpp_primer_plus_5th, function_pointer) {
    vector<string> reviews = {"a", "b", "c"};
    vector<string>::iterator iterator;

    showReviewPtr = showReview;

    for_each(reviews.begin(), reviews.end(), showReviewPtr);
}

// chapter 16 @ page 885 in book
TEST(cpp_primer_plus_5th, vector) {
    vector<string> reviews {"a", "b", "c"};
    vector<string>::iterator iterator;

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