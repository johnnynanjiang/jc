add_executable(
        unit_tests
        example_add.cpp
        example_subtract.cpp
)

target_link_libraries(
        unit_tests
        gtest_main
        example
)

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)

### >>> leetcode tests
add_executable(
        leetcode_tests
        leetcode/add_two_numbers/add_two_numbers_tests.cpp
        leetcode/longest_substring_without_repeat/longest_substring_without_repeat_tests.cpp
        leetcode/median_of_two_sorted_arrays/solution_tests.cpp
        leetcode/search/search_tests.cpp
        leetcode/search/binary_search_tree_tests.cpp
)

target_link_libraries(
        leetcode_tests
        gtest_main
        leetcode
)

add_test(
        NAME
        leetcode_tests
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/leetcode_tests
)
### <<< leetcode tests

### >>> practice tests
add_executable(
        practice_tests
        practice/string_tests.cpp
        practice/interview_questions_tests.cpp
        practice/book_tests.cpp
)

target_link_libraries(
        practice_tests
        gtest_main
)

add_test(
        NAME
        practice_tests
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/practice_tests
)
### <<< practice tests

### >>> util tests
add_executable(
        util_tests
        util/UtilsTests.cpp
)

target_link_libraries(
        util_tests
        gtest_main
        util
)

add_test(
        NAME
        util_tests
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/util_tests
)
### <<< util tests