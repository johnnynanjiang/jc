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
        leetcode/two_sum/two_sum.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/leetcode/two_sum/two_sum.h
    )

target_include_directories(
    leetcode
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
### <<< Leetcode tests