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
    size_t steps = k % nums.size();

    if (steps == 0) return;

    vector<int> tmp{};
    vector<int>::iterator cutPoint = nums.end() - steps;
    tmp.insert(tmp.begin(), cutPoint, nums.end());
    tmp.insert(tmp.end(), nums.begin(), cutPoint);

    std::swap(nums, tmp);
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

    v = {1, 2};
    k = 3;
    rotate(v, k);
    ASSERT_EQ("{2, 1}", vectorToString(v));
}

/*
 * https://leetcode.com/interview/
 * https://leetcode.com/submissions/detail/251774898/
 * beats 14.39% other submissions
 * could use bit operation instead of string for better performance
 */

bool isValid(uint32_t number) {
    std::string numberAsString = std::to_string(number);

    return numberAsString.find("3") == std::string::npos &&
           numberAsString.find("4") == std::string::npos &&
           numberAsString.find("7") == std::string::npos;
}

char rotate(char c) {
    switch (c) {
        case '0':
            return '0';
        case '1':
            return '1';
        case '2':
            return '5';
        case '5':
            return '2';
        case '6':
            return '9';
        case '8':
            return '8';
        case '9':
            return '6';
        default:
            return ' ';
    }
}

std::string rotateNumberToString(uint32_t number) {
    std::string numberAsString = std::to_string(number);
    std::string rotatedNumberAsString{};

    for (auto c : numberAsString) {
        char rotatedChar = rotate(c);
        rotatedNumberAsString += rotatedChar;
    }

    return rotatedNumberAsString;
}

uint32_t rotateNumber(uint32_t number) {
    return std::stoi(rotateNumberToString(number));
}

bool isGood(uint32_t number) {
    if (isValid(number)) {
        return number != rotateNumber(number);
    }

    return false;
}

uint32_t numberOfGood(uint32_t number) {
    uint32_t count = 0;
    for (uint32_t i = 1; i <= number; ++i) {
        if (isGood(i)) ++count;
    }

    return count;
}

TEST(google_mock_interview, rotatedDigits) {
    ASSERT_TRUE(isValid(1256890));
    ASSERT_FALSE(isValid(123));
    ASSERT_FALSE(isValid(124));
    ASSERT_FALSE(isValid(127));

    ASSERT_EQ("1529860", rotateNumberToString(1256890));
    ASSERT_EQ("15 ", rotateNumberToString(123));
    ASSERT_EQ("1 2", rotateNumberToString(135));

    ASSERT_EQ(1529860, rotateNumber(1256890));
    ASSERT_EQ(15, rotateNumber(123));
    ASSERT_EQ(1, rotateNumber(135));

    ASSERT_TRUE(isGood(1256890));
    ASSERT_FALSE(isGood(01));
    ASSERT_FALSE(isGood(10));
    ASSERT_FALSE(isGood(123));

    ASSERT_EQ(4, numberOfGood(10));
}