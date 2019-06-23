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

### >>> Leetcode tests
add_executable(
    leetcode_tests
        leetcode/add_two_numbers/add_two_numbers_tests.cpp
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
### <<< Leetcode tests

### >>> Practice tests
add_executable(
        practice_tests
        practice/practice.cpp
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
### <<< Practice tests