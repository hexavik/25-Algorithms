cmake_minimum_required(VERSION 3.10)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

# Use for debugging and to avoid memory leaks
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O0")

add_subdirectory(cpp/binary_search)
add_subdirectory(cpp/linear_search)
add_subdirectory(cpp/insertion_sort)
add_subdirectory(cpp/selection_sort)
add_subdirectory(cpp/merge_sort)
add_subdirectory(cpp/quick_sort)
add_subdirectory(cpp/heap_sort)
add_subdirectory(cpp/counting_sort)
