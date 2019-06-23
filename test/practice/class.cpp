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
TEST(practice, template_function_and_class_inheritance) {
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