cmake_minimum_required(VERSION 4.3)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_Structures main.cpp)
add_executable(array_stack stack/implementation/array_stack.cpp
        stack/implementation/array_stack.cpp)
add_executable(dynamic_array_stack stack/problems/dynamic_array_stack.cpp)
add_executable(valid_parentheses stack/problems/valid_parentheses.cpp)
add_executable(remove_all_adjacent_duplicates_in_string stack/problems/remove_all_adjacent_duplicates_in_string.cpp)
add_executable(min_stack stack/problems/min_stack.cpp)
