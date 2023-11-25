cmake_minimum_required(VERSION 3.26)
project(CplusplusTutor)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(hello)
add_subdirectory(ClassDemo)
add_subdirectory(tests)

add_executable(CplusplusTutor main.cpp TestStatic.cpp )
target_link_libraries(CplusplusTutor add )
target_link_libraries(CplusplusTutor PlayerLib)
target_link_libraries(CplusplusTutor test1)
