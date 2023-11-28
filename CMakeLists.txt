cmake_minimum_required(VERSION 3.26)
project(CplusplusTutor)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ClassDemo)
add_subdirectory(tests)
add_subdirectory(derived-class)
add_subdirectory(xmlParse)
add_subdirectory(template-demo)
add_subdirectory(OperatorOverrideDemo)

add_executable(CplusplusTutor main.cpp)

target_link_libraries(CplusplusTutor tests_test1)
