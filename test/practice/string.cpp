//
// Created by Nan Jiang on 2019-06-23.
//

#include "gtest/gtest.h"

#include <string>

using namespace std;

TEST(practice, strcpy) {
    const char * copyFrom = "Hello World!";
    /*
     * why it works? question raised and answered well
     * @ https://stackoverflow.com/questions/56720012/how-come-stdstrcpy-still-works-for-an-destination-like-char-copyto0
     * For the code to compile and run? Yes. For the code to be well-formed? No.
     */
    char copyTo[0];

    std::strcpy(copyTo, copyFrom);

    EXPECT_STREQ("Hello World!", copyTo);
}

TEST(practice, size_of_data_types) {
    EXPECT_EQ(8, sizeof(size_t));
    EXPECT_EQ(1, sizeof(char));
    EXPECT_EQ(2, sizeof(short int));
    EXPECT_EQ(4, sizeof(int));
    EXPECT_EQ(4, sizeof(unsigned int));
    EXPECT_EQ(8, sizeof(long int));
    EXPECT_EQ(4, sizeof(float));
    EXPECT_EQ(8, sizeof(double));
    EXPECT_EQ(8, sizeof(long));
    EXPECT_EQ(8, sizeof(unsigned long long));
    EXPECT_EQ(16, sizeof(long double));
}