//
// Created by Nan Jiang on 2019-06-23.
//

#include "gtest/gtest.h"

#include <string>
#include <map>

#include "interview_questions_tests.h"

using namespace std;

template<class P, class C>
bool isInheritance(P *parent, C *child) {
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

class AA : public A {
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
    A *a = new A();
    AA *aa = new AA();
    B *b = new B();

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

    for (int i = 0; i < size; ++i) {
        total *= a[i];
    }

    for (int i = 0; i < size; ++i) {
        b[i] = total / a[i];
    }
}

std::string convertArrayToString(int arr[], size_t size) {
    std::string str = "[";

    for (int i = 0; i < size - 1; ++i) {
        str += std::to_string(arr[i]) + ", ";
    }

    str += std::to_string(arr[size - 1]) + "]";

    return str;
}

TEST(algorithm, two_array_production) {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[6] = {0};
    size_t size = sizeof(b) / sizeof(*b);

    produceBFromA(a, b, size);

    ASSERT_EQ("[720, 360, 240, 180, 144, 120]", convertArrayToString(b, size));
}


void foo(int a, int b) {
    cout << "foo(int a, int b)" << endl;
}

template<class T>
void foo(T a, T b) = delete;

/* Or explicitly delete long type
void foo(long a, long b) = delete;
{
    cout << "foo(long a, long b)" << endl;
}
*/

TEST(interview_questions, functions_delete) {
    foo(1, 2);
    //foo(1l, 2l);
}

class C {
public:
    C() { cout << "C::C()" << endl; }

    virtual ~C() { cout << "C::~C()" << endl; }
};

class CC : public C {
public:
    CC() : C() { cout << "CC::CC()" << endl; }

    ~CC() { cout << "CC::~CC()" << endl; }
};

/*
 * C++11 §5.3.5/3
 * if ~C() is not virtual, the behaviour of destructor is undefined, e.g.
    C::C()
    CC::CC()
    C::~C()

    the correct behaviour should be:
    C::C()
    CC::CC()
    CC::~CC()
    C::~C()
 */
TEST(interview_questions, virtual_destructor) {
    C *c = new CC();
    delete c;
}


// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/

class Person {
public:
    explicit Person() {}

    explicit Person(string name, string address = "address") : name(name), address(address) {}

    bool operator==(const Person &person) {
        return this->name == person.name && this->address == person.address;
    }

    friend std::ostream &operator<<(std::ostream &os, const Person &person) {
        return os << "Person(name = " + person.name + ", address = " + person.address << ")" << endl;
    }

private:
    string name;
    string address;
};

TEST(interview_questions, class_operators) {
    Person p1("name", "address"), p2("name", "address"), p3("name3");

    cout << p1;
    cout << p2;
    cout << p3;

    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
}

// the question https://leetcode.com/discuss/interview-experience/322703/google-swe-mountain-view-reject
// good explanation on hashmap in C++ https://blog.csdn.net/u010025211/article/details/46653519

TEST(interview_questions, find_elements_in_a_but_not_in_b) {
    int a[] = {1, 2, 2, 3, 4, 5};
    int b[] = {1, 2, 5};
    // expected result is {2, 3, 4}
    std::map<int, int> map;

    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
        if (map.find(a[i]) != map.end()) {
            map[a[i]]++;
        } else {
            map[a[i]] = 1;
        }
    }

    mapToString<int>(map);

    for (int i = 0; i < sizeof(b) / sizeof(int); ++i) {
        if (map.find(b[i]) != map.end()) {
            map[b[i]]--;
        }
    }

    mapToString<int>(map);
}

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

int remove_duplicates_from_sorted_array(int array[], size_t size) {
    int i = 0;
    int j = i;

    if (size == 0 || size == 1) return size;

    while (++j < size) {
        if (array[i] != array[j]) {
            array[++i] = array[j];
        }
    }

    return i + 1;
}

int removeDuplicates(vector<int> &nums) {
    int i = 0;
    int j = i;
    int size = nums.size();

    if (size == 0 || size == 1) return size;

    while (++j < size) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }

    return i + 1;
}

TEST(interview_questions, remove_duplicates_from_sorted_array) {
    int array[] = {0, 0, 1, 2, 2};
    EXPECT_EQ(3, remove_duplicates_from_sorted_array(array, 5));
    std::vector<int> v(array, array + sizeof(array) / sizeof(int));
    ASSERT_EQ("{0, 1, 2, 2, 2}", vectorToString<int>(v));

    int array2[] = {0, 1, 2, 2, 3, 3, 3, 4};
    EXPECT_EQ(5, remove_duplicates_from_sorted_array(array2, 8));
    std::vector<int> v2(array2, array2 + sizeof(array2) / sizeof(int));
    ASSERT_EQ("{0, 1, 2, 3, 4, 3, 3, 4}", vectorToString<int>(v2));
}

TEST(interview_questions, removeDuplicates) {
    vector<int> v;

    v = {0, 0, 1, 2, 2};
    EXPECT_EQ(3, removeDuplicates(v));
    ASSERT_EQ("{0, 1, 2, 2, 2}", vectorToString<int>(v));

    v = {0, 1, 2, 2, 3, 3, 3, 4};
    EXPECT_EQ(5, removeDuplicates(v));
    ASSERT_EQ("{0, 1, 2, 3, 4, 3, 3, 4}", vectorToString<int>(v));
}

/*
 Best Time to Buy and Sell Stock II
 https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
 */

int maxProfit(vector<int> &prices) {
    size_t size = prices.size();
    int profit = 0;

    if (size == 0 || size == 1) return profit;

    size_t i = 0;
    while (i < size - 1) {
        if (prices[i + 1] > prices[i]) {
            profit += prices[i + 1] - prices[i];
        }

        ++i;
    }

    return profit;
}

TEST(interview_questions, maxProfit) {
    vector<int> v;

    v = {1, 2, 4, 3, 9, 1};
    EXPECT_EQ(9, maxProfit(v));

    v = {1, 2, 3, 3, 9, 1};
    EXPECT_EQ(8, maxProfit(v));
}

/*
 Rotate Array
 https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
 */

void rotate(vector<int> &nums, int k) {
    size_t size = nums.size();
    size_t steps = k % size;

    if (steps == 0) return;

    for (size_t j = 0; j < steps; ++j) {
        int tmp = nums[size - 1];
        for (size_t i = size - 1; i > 0; --i) {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
}

TEST(interview_questions, rotateArray) {
    vector<int> v;
    int k;

    v = {1, 2, 3, 4, 5, 6, 7};
    k = 3;

    rotate(v, k);
    ASSERT_EQ("{5, 6, 7, 1, 2, 3, 4}", vectorToString(v));

    v = {-1, -100, 3, 99};
    k = 2;
    rotate(v, k);
    ASSERT_EQ("{3, 99, -1, -100}", vectorToString(v));
}