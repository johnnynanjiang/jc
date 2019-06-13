add_library(example "")

target_sources(
    example
    PRIVATE
        example.cpp
        main.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/example.h
    )

target_include_directories(
    example
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )

### >>> Leetcode tests
add_library(leetcode "")

target_sources(
    leetcode
    PRIVATE
        leetcode/add_two_numbers/add_two_numbers.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/leetcode/add_two_numbers/add_two_numbers.h
    )

target_include_directories(
    leetcode
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
### <<< Leetcode tests