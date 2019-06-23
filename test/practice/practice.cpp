//
// Created by Nan Jiang on 2019-06-23.
//

#include "gtest/gtest.h"

#include <string>

using namespace std;

TEST(practice, book) {
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