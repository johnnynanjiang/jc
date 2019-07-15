//
// Created by Nan Jiang on 2019-06-23.
//

#include "gtest/gtest.h"

#include <string>
#include <thread>

using namespace std;

// C++ Primer Plus 5th Edition, chapter 7 @ page 329 in book
void showReview(const string &review) {
    cout << review << endl;
}

void (*showReviewPtr)(const string &review);

TEST(cpp_primer_plus_5th, function_pointer) {
    vector<string> reviews = {"a", "b", "c"};
    vector<string>::iterator iterator;

    showReviewPtr = showReview;

    for_each(reviews.begin(), reviews.end(), showReviewPtr);
}

// C++ Primer Plus 5th Edition, chapter 16 @ page 885 in book
TEST(cpp_primer_plus_5th, vector_iteration) {
    vector<string> reviews{"a", "b", "c"};
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
bool sortAlphabetically(string &a, string &b) {
    return a < b;
}

// TODO: to be implemented properly
template<typename T>
string toString(T &v) {
    string str = std::to_string(std::forward<T>(v));
    cout << str << endl;
    return str;
}

TEST(cpp_primer_plus_5th, vector_sort) {
    vector<string> reviews{"d", "a", "c", "b"};

    for (string s : reviews) {
        cout << s << endl;
    }

    sort(reviews.begin(), reviews.end(), sortAlphabetically);

    for (string s : reviews) {
        cout << s << endl;
    }
}

// IO library C++ Primer 5th @ page 400 in PDF

TEST(cpp_primer_5th, io_cin) {

}

// C++ Concurrency In Action

void do_something() {
    sleep(10);
    cout << "do something 1" << endl;
}

class background_task {
public:
    void operator ()() {
        cout << "do something 2" << endl;
    }
};

TEST(cpp_cocurrency_in_action, thread) {
    std::thread t(do_something);
    background_task do_something_2;
    std::thread t2(do_something_2);
    std::thread t3{background_task()};
    std::thread t4([]{do_something();});

    t.join();
    t2.join();
    t3.join();
    t4.detach();
}

struct func {
    int& m_number;

    func(int& number) : m_number{number} {} // passing in & here could cause issues

    void operator()() {
        int i = 0;
        while (++i <= m_number) {
            cout << i << endl;
        }
    }
};

TEST(cpp_cocurrency_in_action, thread_access_destroyed_instance) {
    int local_number = 10000;
    func thread_func(local_number);
    std::thread t{thread_func};
    t.detach();

    cout << "Test thread_access_destroyed_instance finished" << endl;
    ASSERT_FALSE(t.joinable());
}

void f(int i, string const & s, string ss) {
    cout << i << ", " << s << ", " << ss << endl;
}

TEST(cpp_cocurrency_in_action, pass_parameters) {
    thread t(f, 1, "a", "A");
    thread t2(f, 2, "b", "B");

    t.join();
    t2.join();
}

// 数据结构、算法与应用 C++语言描述

template<class T>
void make2DArray(T ** &array, size_t rowSize, size_t columnSize) {
    try {
        array = new T*[rowSize];

        for (size_t i = 0; i < rowSize; ++i) {
            array[i] = new T[columnSize] {};
        }
    } catch (bad_alloc) {
        cout << "exception: bad_alloc" << endl;
    }
}

template<class T>
void print2DArray(T ** const &array, size_t rowSize, size_t columnSize) {
    for (size_t i = 0; i < rowSize; ++i) {
        for (size_t j = 0; j < columnSize; ++j) {
            cout << array[i][j] << ", ";
        }
        cout << endl;
    }
}

template<class T>
void delete2DArray(T ** &array, size_t rowSize) {
    for (size_t i = 0; i < rowSize; ++i) {
        delete []array[i];
    }

    delete []array;
}

TEST(data_structure_algorithm_application_cpp, new_2d_array) {
    int ** array;
    size_t rowSize = 10, columnSize = 10;

    make2DArray<int>(array, rowSize, columnSize);
    print2DArray<int>(array, rowSize, columnSize);
    delete2DArray<int>(array, rowSize);
}

// recursive functions

uint32_t fibonacci(uint32_t num) {
    if (num == 0) return 0;
    if (num == 1) return 0;
    if (num == 2) return 1;

    return fibonacci(num - 2) + fibonacci(num - 1);
}

TEST(data_structure_algorithm_application_cpp, recursive) {
    ASSERT_EQ(0, fibonacci(0));
    ASSERT_EQ(0, fibonacci(1));
    ASSERT_EQ(1, fibonacci(2));
    ASSERT_EQ(1, fibonacci(3));
    ASSERT_EQ(2, fibonacci(4));
    ASSERT_EQ(3, fibonacci(5));
    ASSERT_EQ(5, fibonacci(6));
    ASSERT_EQ(8, fibonacci(7));
    ASSERT_EQ(13, fibonacci(8));
}