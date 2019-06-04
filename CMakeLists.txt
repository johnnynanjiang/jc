cmake_minimum_required(VERSION 3.14)
project(jc)

set(CMAKE_CXX_STANDARD 14)

### Boost >>> ###
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.45.0 COMPONENTS lib/boost_1_70_0/libs)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(jc src/main.cpp)
    target_link_libraries(progname ${Boost_LIBRARIES})
endif()
### <<< Boost ###

add_executable(jc src/main.cpp)
