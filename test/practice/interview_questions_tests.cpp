//
// Created by Nan Jiang on 2019-06-23.
//

#include "gtest/gtest.h"

#include <string>

using namespace std;

template<class P, class C>
bool isInheritance(P * parent, C * child) {
    return dynamic_cast<P *>(child) != NULL;
}

class A {
public:
    virtual std::string getName();
private:
    std::string name = "name of A";
};

std::string A::getName() {
    return this->name;
}

class AA: public A {
public:
    virtual std::string getName() override;
private:
    std::string name = "name of AA";
};

std::string AA::getName() {
    return this->name;
}

class B {
public:
    virtual std::string getName();
private:
    std::string name = "name of B";
};

std::string B::getName() {
    return this->name;
}

template<class P, class C>
bool isBaseOf() {
    return std::is_base_of<P, C>();
}

// source @ https://www.toptal.com/c-plus-plus/interview-questions
TEST(template_function_and_class_inheritance, is_base_of) {
    A * a = new A();
    AA *  aa = new AA();
    B * b = new B();

    std::cout << a->getName() << std::endl;
    std::cout << aa->getName() << std::endl;
    std::cout << b->getName() << std::endl;

    ASSERT_TRUE(isInheritance(a, aa));
    ASSERT_FALSE(isInheritance(a, b));

    bool result;
    result = isBaseOf<A, AA>();
    ASSERT_TRUE(result);
    result = isBaseOf<A, B>();
    ASSERT_FALSE(result);
}

template<class A, class B>
bool isSameClass() {
    return typeid(A) == typeid(B);
}

TEST(template_function_and_class_inheritance, is_same_class) {
    bool result;
    result = isSameClass<A, A>();
    ASSERT_TRUE(result);
    result = isSameClass<A, AA>();
    ASSERT_FALSE(result);
    result = isSameClass<A, B>();
    ASSERT_FALSE(result);
}

void produceBFromA(int a[], int b[], size_t size) {
    long total = 1;

    for(int i=0; i<size; ++i) {
        total *= a[i];
    }

    for(int i=0; i<size; ++i) {
        b[i] = total/a[i];
    }
}

std::string convertArrayToString(int arr[], size_t size) {
    std::string str = "[";

    for(int i=0; i<size-1; ++i) {
        str += std::to_string(arr[i]) + ", ";
    }

    str += std::to_string(arr[size-1]) + "]";

    return str;
}

TEST(algorithm, two_array_production) {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[6] = {0};
    size_t size = sizeof(b)/sizeof(*b);

    produceBFromA(a, b, size);

    ASSERT_EQ("[720, 360, 240, 180, 144, 120]", convertArrayToString(b, size));
}