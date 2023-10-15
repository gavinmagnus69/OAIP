cmake_minimum_required(VERSION 3.25)
project(binaryheap)

set(CMAKE_CXX_STANDARD 23)

add_executable(binaryheap main.cpp shared_ptr.h linkedlist.h binary_heap.h)
