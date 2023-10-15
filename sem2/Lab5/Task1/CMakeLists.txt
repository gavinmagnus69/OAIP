cmake_minimum_required(VERSION 3.25)
project(queue)

set(CMAKE_CXX_STANDARD 23)

add_executable(queue main.cpp My_queue.h shared.h My_queue.cpp deq.h)
